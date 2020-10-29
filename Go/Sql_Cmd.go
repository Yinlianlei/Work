package main

import (
	"./sql"
	"fmt"
	//"time"
)

func Connection2mysql()sql.MySQLConnector{
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
	mysql := sql.NewMqSQLConnector(&option,tables)
	return mysql
}

func Sql_SelectFromDatabase(input string,database string,limit string)error{
	mysql := Connection2mysql()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	RE,err := SQL.Query("select "+input+" from "+database)
	if err!=nil{
		panic(err)
	}
	for index := range RE{
		fmt.Println(string(RE[index][input]))
	}
	return nil
}

func Sql_SelectAthorCopyright(input string)error{
	mysql := Connection2mysql()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	tmp,err := SQL.Query("select `tx_hash` from eth_transaction_log_copyright where data = `"+input+"`")

	if err!=nil{
		panic(err)
	}

	if string(tmp[0]["tx_hash"])==""{
		fmt.Println("Don't have this copyright")
		return nil
	}

	RE,err := SQL.Query("select `from` from eth_transaction_scan where `hash` = `"+string(tmp[0]["tx_hash"])+"`")
	
	if err!=nil{
		fmt.Println(err)
		return nil
	}else if RE == nil || string(RE[0]["from"])==""{
		fmt.Println("Not have this copyright")
		return nil
	}
	
	fmt.Println(string(RE[0]["from"]))
	return nil
}