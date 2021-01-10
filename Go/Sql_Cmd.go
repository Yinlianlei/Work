package main

import (
	"fmt"
	//"time"
)

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

	tmp,err := SQL.Query("select `tx_hash` from eth_transaction_log_copyright where data = \""+input+"\"")

	if err!=nil && string(tmp[0]["tx_hash"])==""{
		fmt.Println("Don't have the data")
		return nil
	}

	RE,err := SQL.Query("select `from` from eth_transaction_scan where `hash` = \""+string(tmp[0]["tx_hash"])+"\"")
	
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

func Sql_SelectLogin(id string, passwd string):error{
	mysql := Connection2mysql()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	RE,err := SQL.Query("select Passwd,Id from User where "+id+"=Id and "+passwd+"=Passwd")

	fmt.Println(RE)
}
