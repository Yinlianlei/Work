package main

import (
	"./sql"
	"fmt"
	"time"
)

var mainNet string ="https://mainnet.infura.io/v3/2e6d9331f74d472a9d47fe99f697ca2b"

func TestBlockScanner_Start()  {
	
	requestor := NewETHRPCRequester(mainNet)

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
	tables = append(tables,sql.Transaction_Scan{},sql.Transaction_Scan{})
	mysql := sql.NewMqSQLConnector(&option,tables)
	fmt.Println("POP")
	CMD := make(chan bool,1)
	scanner := NewBlockScanner(*requestor,mysql)
	err := scanner.Start(CMD)
	
	if err!=nil{
		panic(err)
	}
	for{
		if il,ok:=<-CMD;ok&&il!=true{
			time.Sleep(2 * time.Second) 
		}else{
			break
		}
	}
	



}
