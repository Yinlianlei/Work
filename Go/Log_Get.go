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

func (logget *LogGet)GET_Block(Number string)error{
	fmt.Println(Number)
	ten := logget.hexToTen(Number)
	fmt.Println(ten)
	fullBlock, err := logget.ethRequester.GetBlockInfoByNumber(ten)
	il,_ := json.Marshal(fullBlock.Transactions)
	fmt.Println(string(il))
	if err != nil{
		return err
	}
	tx := logget.mysql.Db.NewSession()//
	defer tx.Close()
	fmt.Println("Failed")

	blocklog:= sql.Log{}
	//_, err = tx.Where("block_Hash=?", fullBlock.Address).Get(&blocklog)
	if err == nil && blocklog.Address == "" {
		//blocklog.BlockNumber = logget.hexToTen(string(fullBlock.BlockNumber)).String()
		//blocklog.BlockHash = 
		//blocklog.Timestamp = 
		//blocklog.BlockHash = logget.hexToTen(fullBlock.BlockHash).String()
		//blocklog.Logs = 
		/*
		if _, err := tx.Insert(&blocklog); err != nil{//insert
			tx.Rollback()
			return err
		}
		*/
		fmt.Println("*Insert*")
	}
	return nil
}

func (logget *LogGet)GET()error{
	fullBlock, err := logget.ethRequester.GetTransactionReceipt(logget.logs.Address)
	//ten, _ := new(big.Int).SetString("8896244",7)
	il,_ := json.Marshal(fullBlock)
	fmt.Println(string(il))
	if err != nil{
		return err
	}
	tx := logget.mysql.Db.NewSession()//
	defer tx.Close()
	fmt.Println("Failed")

	blocklog:= sql.Log{}
	//_, err = tx.Where("block_Hash=?", fullBlock.Address).Get(&blocklog)
	if err == nil && blocklog.Address == "" {
		//blocklog.BlockNumber = logget.hexToTen(string(fullBlock.BlockNumber)).String()
		//blocklog.BlockHash = 
		//blocklog.Timestamp = 
		//blocklog.BlockHash = logget.hexToTen(fullBlock.BlockHash).String()
		//blocklog.Logs = 
		/*
		if _, err := tx.Insert(&blocklog); err != nil{//insert
			tx.Rollback()
			return err
		}
		*/
		fmt.Println("*Insert*")
	}
	return nil
}

func (logget *LogGet)GET_Transaction_ByHash()error{
	fullBlock, err := logget.ethRequester.GetTransactionByHash(logget.logs.Address)
	//ten, _ := new(big.Int).SetString("8896244",7)
	il,_ := json.Marshal(fullBlock)
	fmt.Println(string(il))
	if err != nil{
		return err
	}
	tx := logget.mysql.Db.NewSession()//
	defer tx.Close()
	fmt.Println("Failed")

	blocklog:= sql.Log{}
	//_, err = tx.Where("block_Hash=?", fullBlock.Address).Get(&blocklog)
	if err == nil && blocklog.Address == "" {
		//blocklog.BlockNumber = logget.hexToTen(string(fullBlock.BlockNumber)).String()
		//blocklog.BlockHash = 
		//blocklog.Timestamp = 
		//blocklog.BlockHash = logget.hexToTen(fullBlock.BlockHash).String()
		//blocklog.Logs = 
		/*
		if _, err := tx.Insert(&blocklog); err != nil{//insert
			tx.Rollback()
			return err
		}
		*/
		fmt.Println("*Insert*")
	}
	return nil
}

func (scanner *LogGet) LogInit(address string) error  {
	//_, err := scanner.mysql.Db.Desc("create_time").Where("fork = ?",false).Get(scanner.logs.ContractAddress)
	//if err != nil{return err}
	if scanner.logs.Address == ""{
		fmt.Printf("Adress is : %s\n",address)
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
	//tables = append(tables,sql.Log{},sql.Transaction{})
	mysql := sql.NewMqSQLConnector(&option,tables)

	logget:= NewLogGet(*requestor,mysql)
	err := logget.LogStart(address)
	if err != nil {
		panic(err)
	}
	fmt.Println("*end*")

	return nil
}