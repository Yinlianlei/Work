package main

import (
	"fmt"
	"time"
	"./sql"
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

func Sql_SelectLogin(id string, passwd string) (string,error){
	mysql := Connection2mysql()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	RE := []sql.User{}
	SQL.Table("eth_user").Where("`id` = ? AND `passwd` = ?",id,passwd).Find(&RE)
	//("select Passwd,Id,Address from User where "+id+"=Id and "+passwd+"=Passwd")

	//fmt.Println(RE[0].Id)

	//fmt.Println((RE))
	if len(RE)==0 {
		return "ERROR2",nil
	}
	//fmt.Println(string(RE[0]["Address"]))
	return string(RE[0].Address),nil
}

func Sql_SelectRegister(id string, passwd string)(string,error){
	mysql := Connection2mysql()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	re,_  := SQL.Query("select id from eth_user where Id=\""+id+"\"")

	if re!=nil{
		return "ERROR1",nil
	}

	address:="123"
	In:=[]sql.User{}
	In = append(In,sql.User{Id:id,Passwd:passwd,Address:address})
	
	if _, err := SQL.Insert(&In); err != nil{//insert
		SQL.Rollback()
		return "ERROR2",err
	}


	return "",nil
}

func Sql_OnloadDetail(title string, word string, address string, tags []string) (string,error){
	//EXAMPLE:
	/*
	var tags =[]string{"1","2"}
	Sql_OnloadDetail("银链锁心",
	"仿佛林间的小鹿一般，那属于孩子特有的纯真与自然.",
	"0xdfff3a34b669374ac670e3ed42e395d7a57da44f", 
	tags)
	*/

	mysql := Connection2mysql()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

	In := []sql.Detail{}
	In = append(In,sql.Detail{Title:title,Word:word,Tags:tags,Address:address,Time:time.Now()})
	
	if _, err := SQL.Insert(&In); err != nil{//insert
		SQL.Rollback()
		return "ERROR_Can't insert detail "+title+" into mysql",err
	}

	return "",nil
}