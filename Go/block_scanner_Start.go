package main

import (
	//"./sql"
)

func TestBlockScanner_Start()  {
	requestor := NewETHRPCRequester(mainNet)
	mysql:= Connection2mysql()
	CMD := make(chan bool,1)
	scanner := NewBlockScanner(*requestor,mysql)
	err := scanner.Start(CMD)
	
	if err!=nil{
		panic(err)
	}
	
	for{
		if _,ok:=<-CMD;ok{
			break
		}
	}
	



}

/*


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
	tables = append(tables,sql.Block{},sql.TransactionScan{})
	mysql := sql.NewMqSQLConnector(&option,tables)
*/
