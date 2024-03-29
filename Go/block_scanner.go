package main

import (
	"errors"
	"./sql"
	"fmt"
	"math/big"
	"strings"
	"time"
	"encoding/json"
	"sync"
	"./model"
)
type BlockScanner struct {
	ethRequester ETHRPCRequester    // 以太坊 rpc 请求者实例
	mysql        sql.MySQLConnector // 数据库连接者实例
	lastBlock    *sql.Block         // 用来存储每次遍历后，存储上一次的区块
	lastNumber   *big.Int           // 上一次区块的区块号
	fork         bool               // 用来监听是否发生了分叉
	stop         chan bool          // 用来控制是否停止遍历的管道
	lock 		 sync.Mutex			// 控制并发
}

func NewBlockScanner(requester ETHRPCRequester, mysql sql.MySQLConnector) *BlockScanner {
	return &BlockScanner{
		ethRequester: requester,
		mysql:        mysql,
		lastBlock:    &sql.Block{},
		fork:		  false,
		stop:         make(chan bool,1),
		lock:		  sync.Mutex{},
	}
}

func (scanner *BlockScanner) Start(CMD chan bool) error {
	scanner.lock.Lock()
	

	init := func() error {
		// 寻找出上一次成功遍历的区块
		_, err := scanner.mysql.Db.
			Desc("create_time").
			Where("fork = ?", false).
			Get(scanner.lastBlock )
		if err != nil {
			return err
		}
		if scanner.lastBlock.BlockHash == "" {
			// 首次启动，从节点中获取，并初始化
			ad,_ := new(big.Int).SetString("9052920",10)
			//latestBlockNumber, err := scanner.ethRequester.GetLatestBlockNumber()
			latestBlockNumber := ad

			if err != nil {
				return err
			}
			latestBlock,err := scanner.ethRequester.GetBlockInfoByNumber(latestBlockNumber)
			if err != nil {
				return err
			}
			if latestBlock.Number == "" {
				panic(latestBlockNumber.String())
			}
			scanner.lastBlock.BlockHash   = latestBlock.Hash
			scanner.lastBlock.ParentHash  = latestBlock.ParentHash
			scanner.lastBlock.BlockNumber = latestBlock.Number
			scanner.lastBlock.CreateTime  = scanner.hexToTen(latestBlock.Timestamp).Int64()
			scanner.lastNumber = latestBlockNumber
		}else{
			scanner.lastNumber, _ = new(big.Int).SetString(scanner.lastBlock.BlockNumber, 10)
			// 下面加 1，因为上一次数据库存的是已经遍历完了的
			scanner.lastNumber.Add(scanner.lastNumber,new(big.Int).SetInt64(1))
		}
		return nil
	}

	if err := init();err != nil {
		return err
	}
	
	execute := func(i *big.Int) {
		if err := scanner.scan(i); nil != err {
			scanner.log(err.Error())
			return
		}
		time.Sleep(100 * time.Microsecond) // 延迟一秒开始下一轮
	}

	// 启动一个协程来遍历区块
	go func(){
		i,_:=scanner.ethRequester.GetLatestBlockNumber()
		fmt.Println("Newest Block Number Is ",i)
		t1 := time.Now()
		for {
			select {
			case <-scanner.stop: // 监听是否退出遍历
				scanner.log("finish block scanner!")
				CMD<-true
				return
			default:
				if !scanner.fork {
					t2 := time.Now()
					t3 := t2.Sub(t1)
					if(t3 >= 5*time.Second ){
						fmt.Println("**************************************************")
						scanner.GetCopyright()
						fmt.Println("**************************************************")
						t1 = time.Now()
					}
					//fmt.Println(scanner.lastNumber,i )
					if i.Cmp(scanner.lastNumber) == -1 {
						//scanner.Stop()
						i,_ = scanner.ethRequester.GetLatestBlockNumber()
						time.Sleep(5*time.Second)
						fmt.Println(i)
					}
					execute(i)
					continue
				}
				scanner.fork = false
			}
		}
	}()
	return nil
	/*
	t1 := time.Now()
				t2 := time.Now()
			t3 := t2.Sub(t1)
			if(t3 >= 15*time.Second ){
				fmt.Println("Sleep")
				time.Sleep(5*time.Second)//sleep
				t1 = time.Now()
			}
								if i ==  scanner.lastNumber{
						scanner.Stop()
						continue
					}
	*/
}

func (scanner *BlockScanner) Stop() {
	scanner.lock.Unlock()
	scanner.stop <- true
}

func (scanner *BlockScanner) log(args ...interface{})  {
	fmt.Println(args...)
}

// 检测分叉，返回 true 是分叉
func (scanner *BlockScanner) forkCheck(currentBlock *sql.Block) bool {
	if currentBlock.BlockNumber == "" {
		panic("invalid block")
	}
	if scanner.lastBlock.BlockHash == currentBlock.BlockHash || scanner.lastBlock.BlockHash == currentBlock.ParentHash {
		scanner.lastBlock = currentBlock // 更新
		return false
	}
	// 获取出最初开始分叉的那个区块
	forkBlock, err := scanner.getForkBlock(currentBlock.ParentHash)
	if err != nil {
		panic(err)
	}
	scanner.lastBlock = forkBlock // 更新。从这个区块开始，其之后的都是分叉的

	// 修改数据库记录，将分叉区块标记好
	numberEnd := ""
	if strings.HasPrefix(currentBlock.BlockNumber, "0x") {
		c, _ := new(big.Int).SetString(currentBlock.BlockNumber[2:], 16)
		numberEnd = c.String()
	} else {
		c, _ := new(big.Int).SetString(currentBlock.BlockNumber, 10)
		numberEnd = c.String()
	}
	numberFrom := forkBlock.BlockNumber
	_, err = scanner.mysql.Db.
		Table(sql.Block{}).
		Where("block_number > ? and block_number <= ?", numberFrom, numberEnd). // 区块号范围内
		Update(map[string]bool{"fork": true})
	if err != nil {
		panic(fmt.Errorf("update fork block failed %s", err.Error()))
	}
	return true
}

func (scanner *BlockScanner) getForkBlock(parentHash string) (*sql.Block, error) {
	// 获取当前区块的父区块，分叉从父区块开始
	parent := sql.Block{}
	_, err := scanner.mysql.Db.Where("block_hash=?", parentHash).Get(&parent)
	if err == nil && parent.BlockNumber != "" {
		return &parent, nil
	}
	// 数据库没有父区块记录，准备从以太坊接口获取
	parentFull, err := scanner.retryGetBlockInfoByHash(parentHash)
	if err != nil {
		return nil, fmt.Errorf("分叉严重错误，需要重启区块扫描 %s",err.Error())
	}
	// 继续递归往上查询，直到在数据库中有它的记录
	return scanner.getForkBlock(parentFull.ParentHash)
}

// 定义一个将16进制转为10进制大数的函数
func (scanner *BlockScanner) hexToTen(hex string) *big.Int {
	ten, _ := new(big.Int).SetString(hex[2:], 16)
	return ten
}

// 区块号存在，信息获取为空，可能是以太坊网络延时问题，重试策略函数
func (scanner *BlockScanner) retryGetBlockInfoByNumber(targetNumber *big.Int) (*model.Transaction_Scan,error) {
	Retry:
		fullBlock, err := scanner.ethRequester.GetBlockInfoByNumber2(targetNumber)
		if err != nil {
			errInfo := err.Error()
			if strings.Contains(errInfo,"empty") {
				// 区块号存在，信息获取为空，可能是以太坊网络延时问题，直接重试
				scanner.log("获取区块信息，重试一次.....",targetNumber.String())
				goto Retry
			}
			return nil,err
		}
	return fullBlock,nil
}

func (scanner *BlockScanner) retryGetBlockInfoByHash(hash string) (*model.Transaction_Scan,error) {
	Retry:
		fullBlock, err := scanner.ethRequester.GetBlockInfoByHash1(hash)
		if err != nil {
			errInfo := err.Error()
			if strings.Contains(errInfo,"empty") {
				// 区块号存在，信息获取为空，可能是以太坊网络延时问题，直接重试
				scanner.log("获取区块信息，重试一次.....",hash)
				goto Retry
			}
			return nil,err
		}
	return fullBlock,nil
}

// 扫描区块
func (scanner *BlockScanner) scan(i *big.Int) error {
	// 获取公链上最新生成的区块
	//newBlockNumber, err := scanner.ethRequester.GetLatestBlockNumber()
	//if err != nil {
	//	return err
	//}

	latestNumber := i
	targetNumber := scanner.lastNumber
	// 比较区块号大小
	// -1 if x <  y
	//  0 if x == y
	// +1 if x >  y
	if latestNumber.Cmp(scanner.lastNumber) < 0 {
		// 小，则等待新区块生成
		//scanner.Stop()
		return nil
	}
	// 获取区块信息
	fullBlock, err := scanner.retryGetBlockInfoByNumber(targetNumber)
	if err != nil {
		return err
	}
	// 区块号自增 1
	scanner.lastNumber.Add(scanner.lastNumber, new(big.Int).SetInt64(1))

	// 开启数据库事务
	tx := scanner.mysql.Db.NewSession()
	defer tx.Close()

	// 准备保存区块信息，先判断当前区块记录是否已经存在
	block := sql.Block{}
	_, err = tx.Where("block_hash=?", fullBlock.Hash).Get(&block)
	if err == nil && block.Id == 0 {
		// 不存在，进行添加
		block.BlockNumber = scanner.hexToTen(fullBlock.Number).String()
		block.ParentHash = fullBlock.ParentHash
		block.CreateTime = scanner.hexToTen(fullBlock.Timestamp).Int64()
		block.BlockHash  = fullBlock.Hash
		//block.Fork = false
		if _, err := tx.Insert(&block); err != nil {
			tx.Rollback() // 事务回滚
			return err
		}
	}
	// 检查区块是否分叉
	if scanner.forkCheck(&block) {
		data,_ := json.Marshal(fullBlock)
		scanner.log("分叉！",string(data))
		tx.Commit()
		scanner.fork = true  // 发生分叉
		return errors.New("fork check")
	}

	// 解析区块内数据，读取内部的 “transactions” 交易信息，分析得出各种合约事件
	//it,_:=json.Marshal(fullBlock.Transactions[1:4])
	//fmt.Println(string(it))
	scanner.log("number: \t", scanner.hexToTen(fullBlock.Number),"\nhash:\t\t",fullBlock.Hash)
	scanner.log("ParentHash:\t",fullBlock.ParentHash,"\nNonce:\t\t",fullBlock.Nonce,"\nTimestamp:\t",fullBlock.Timestamp,"\nTransaction:")
	for index, transaction := range fullBlock.Transactions {
		// 下面的打印操作模拟自定义处理。对于每条 tx，我们是完全可以进一步从里面提取信息的！
		scanner.log(index,"==> ",transaction.Hash)
		if index > 5{
			// 控制只打印 5 条
			break
		}
	}
	scanner.log("scan block finish \n=================")
	// 数据库保存交易信息
	if _, err = tx.Insert(&fullBlock.Transactions); err != nil {
		tx.Rollback() // 事务回滚
		return err
	}
	return tx.Commit()
}

func (scanner *BlockScanner)GetCopyright()error{
	contract := "0xdfff3a34b669374ac670e3ed42e395d7a57da44f"
	//contract := "0x8f19fb82e4b56610f687644897c899d6e5916186"
	SQL :=scanner.mysql.Db.NewSession()
	defer SQL.Close()

	op := []sql.TransactionScan{}
	//op1 := []sql.TransactionLogCopyright{}
	//op2 := []sql.TransactionLogPurchase{}

	err := SQL.Table("eth_transaction_scan").Where("`to` = ?", contract).Find(&op)
	if err != nil{
		panic(err)
	}

	if op != nil {
		for _,i := range op[:] {
			fullBlock, err := scanner.ethRequester.GetTransactionReceipt(i.Hash)
			if err != nil{
				return err
			}		

			for _,LogS := range fullBlock.Logs{
				if (len(LogS.Data[2:])==64){
					blocklog := sql.TransactionLogCopyright{}
					blocklog.Id = 0
					blocklog.BlockNumber = scanner.hexToTen(string(fullBlock.BlockNumber)).String()
					blocklog.BlockHash = fullBlock.BlockHash
					blocklog.Address =  LogS.Address
					blocklog.Topics = LogS.Topics
					blocklog.From = fullBlock.From
					blocklog.To = fullBlock.To
					blocklog.Data = LogS.Data
					blocklog.TxHash = LogS.TxHash
					blocklog.TxIndex = LogS.TxIndex
					blocklog.Index = LogS.Index
					blocklog.Removed = LogS.Removed
					if _, err := SQL.Insert(&blocklog); err != nil{//insert
						SQL.Rollback()
						return err
					}
				}else if (len(LogS.Data[2:])==192){
					blocklog := sql.TransactionLogPurchase{}
					blocklog.Id = 0
					blocklog.BlockNumber = scanner.hexToTen(string(fullBlock.BlockNumber)).String()
					blocklog.BlockHash = fullBlock.BlockHash
					blocklog.Address =  LogS.Address
					blocklog.Topics = LogS.Topics
					blocklog.From = fullBlock.From
					blocklog.To = fullBlock.To
					for i:=0;i<(len(LogS.Data)-2)/64;i++{
						fmt.Println(i,LogS.Data[2+i*64:66+i*64])
						blocklog.Data = append(blocklog.Data,LogS.Data[2+i*64:66+i*64])
					}
					blocklog.TxHash = LogS.TxHash
					blocklog.TxIndex = LogS.TxIndex
					blocklog.Index = LogS.Index
					blocklog.Removed = LogS.Removed
					if _, err := SQL.Insert(&blocklog); err != nil{//insert
						SQL.Rollback()
						return err
					}
				}else{
					return nil
				}
			}
		}
	}

	SQL.Query("truncate table eth_transaction_scan")
	return nil
}