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
			blocklog.BlockNumber = logget.hexToTen(string(fullBlock.BlockNumber)).String()
			blocklog.BlockHash = fullBlock.BlockHash
			blocklog.Address =  LogS.Address
			blocklog.Topics = LogS.Topics
			blocklog.Data = append(blocklog.Data,LogS.Data)
			blocklog.TxHash = LogS.TxHash
			blocklog.TxIndex = LogS.TxIndex
			blocklog.Index = LogS.Index
			blocklog.Removed = LogS.Removed
			if _, err := tx.Insert(&blocklog); err != nil{//insert
				tx.Rollback()
				return err
			}
		}else{
			blocklog := sql.TransactionLogPurchase{}
			blocklog.BlockNumber = logget.hexToTen(string(fullBlock.BlockNumber)).String()
			blocklog.BlockHash = fullBlock.BlockHash
			blocklog.Address =  LogS.Address
			blocklog.Topics = LogS.Topics
			for i:=0;i<(len(LogS.Data)-2)/64;i++{
				fmt.Println(i,LogS.Data[2+i*64:66+i*64])
				blocklog.Data = append(blocklog.Data,LogS.Data[2+i*64:66+i*64])
			}
			blocklog.TxHash = LogS.TxHash
			blocklog.TxIndex = LogS.TxIndex
			blocklog.Index = LogS.Index
			blocklog.Removed = LogS.Removed
			if _, err := tx.Insert(&blocklog); err != nil{//insert
				tx.Rollback()
				return err
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

func TestGetLogByHash(ad string)error{
	mainNet := "https://ropsten.infura.io/v3/2e6d9331f74d472a9d47fe99f697ca2b"
	requestor := NewETHRPCRequester(mainNet)
	address := ad
	fmt.Println(ad)

	option := sql.MysqlOptions{
		Hostname: "127.0.0.1",
		Port: "3306",
		DbName: "eth_relay",
		User: "Yinlianlei",
		Password: "1114561520",
		TablePrefix: "eth_",
		MaxOpenConnections: 10,
		MaxIdleConnections:5,
		ConnMaxLifetime: 15,
	}
	tables := []interface{}{}
	tables = append(tables,sql.TransactionLogCopyright{},sql.TransactionLogPurchase{})
	mysql := sql.NewMqSQLConnector(&option,tables)

	logget:= NewLogGet(*requestor,mysql)
	err := logget.LogStart(address)
	if err != nil {
		panic(err)
	}

	return nil
}
