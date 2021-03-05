package main

import(
	"./sql"
	"sync"
	"time"
	"strings"
	"math/big"
	"fmt"
	"encoding/json"
)

type LogGet struct{
	ethRequester ETHRPCRequester
	logs sql.Log
	mysql sql.MySQLConnector
	lock sync.Mutex
}

func NewLogGet(requester ETHRPCRequester, mysql sql.MySQLConnector)*LogGet{
	return &LogGet{
		ethRequester: requester,
		mysql: mysql,
		lock: sync.Mutex{},
	}
}

func (scanner * LogGet) hexToTen(hex string) *big.Int{
	if !strings.HasPrefix(hex,"0x"){
		ten, _ := new (big.Int).SetString(hex,10)
		return ten
	}
	ten, _ := new(big.Int).SetString(hex[2:], 16)
	return ten
}

func (scanner *LogGet)log(args ...interface{})  {
	fmt.Println(args...)
}

func (logget *LogGet)LogStart(address string)error{
	logget.lock.Lock()
	if err := logget.LogInit(address);err!=nil{
		logget.lock.Unlock()
		return err
	}
	if err := logget.GET();err != nil{
		logget.log(err.Error())
		return err
	} 
	time.Sleep(1*time.Second)

	if err := logget.LogInit(address);err != nil {
		logget.log(err.Error())
		return err
	}

	return nil
}

func (logget *LogGet)GET()error{
	fullBlock, err := logget.ethRequester.GetTransactionReceipt(logget.logs.Address)
	il,_ := json.Marshal(fullBlock)
	fmt.Println(string(il))
	if err != nil{
		return err
	}
	tx := logget.mysql.Db.NewSession()
	defer tx.Close()

	for _,LogS := range fullBlock.Logs{
		if (len(LogS.Data[2:])==64){
			blocklog := sql.TransactionLogCopyright{}
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
	return nil
}

func (scanner *LogGet) LogInit(address string) error  {
	if scanner.logs.Address == ""{
		//fmt.Printf("Adress is : %s\n",address)
		scanner.logs.Address = address
	}
	return nil
}

func GetLogByHash(ad string)error{
	//contract := "0xDFFF3A34b669374Ac670e3ED42e395D7a57dA44f"
	requestor := NewETHRPCRequester(mainNet)
	address := ad

	mysql:=Connection2mysql()
	//fmt.Println(contract)
	
	logget:= NewLogGet(*requestor,mysql)
	err := logget.LogStart(address)
	if err != nil {
		panic(err)
	}

	return nil
}

func GetCopyright(){
	contract := "0xdfff3a34b669374ac670e3ed42e395d7a57da44f"
	//contract := "0x8f19fb82e4b56610f687644897c899d6e5916186"
	mysql:=Connection2mysql()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	op := []sql.TransactionScan{}
	//op1 := []sql.TransactionLogCopyright{}
	//op2 := []sql.TransactionLogPurchase{}

	err := SQL.Table("eth_transaction_scan").Where("`to` = ?", contract).Find(&op)
	if err != nil{
		panic(err)
	}

	fmt.Println("Copyright comfirm!")

	if op != nil {
		for k,i := range op[:] {
			j,_  := json.Marshal(i.Hash)
			fmt.Println(string(j))
			GetLogByHash(op[k].Hash)
		}
	}

	SQL.Query("truncate table eth_transaction_scan")

}