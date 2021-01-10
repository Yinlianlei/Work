package main

import (
	"fmt"
	//"time"
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

<<<<<<< HEAD
func Sql_SelectLogin(id string, passwd string) (string,error){
=======
func Sql_SelectLogin(id string, passwd string):error{
>>>>>>> 2ffa2e6d6bea06146e28154b2f7d2197afa0c4cf
	mysql := Connection2mysql()
	SQL :=mysql.Db.NewSession()
	defer SQL.Close()

<<<<<<< HEAD
	RE := []sql.User{}
	err := SQL.Table("eth_user").Where("`id` = ? AND `passwd` = ?",id,passwd).Find(&RE)
	//("select Passwd,Id,Address from User where "+id+"=Id and "+passwd+"=Passwd")

	//fmt.Println(RE[0].Id)
	if err!=nil{
		return "",err
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
=======
	RE,err := SQL.Query("select Passwd,Id from User where "+id+"=Id and "+passwd+"=Passwd")

	fmt.Println(RE)
>>>>>>> 2ffa2e6d6bea06146e28154b2f7d2197afa0c4cf
}
