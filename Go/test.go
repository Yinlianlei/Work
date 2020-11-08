package main

import (
	"fmt"
	"./sql"
	//"encoding/json"
	"time"
)

func testGo(){
	//fmt.Println("233")
	mysql :=Connection2mysql_ts()
	op:= []sql.Block{}
	//mysql.Db.Insert(&op)
	//var date string
	//var strings []string
	mysql.Db.Table("eth_block").Find(&op)
	//i,_ := json.Marshal(op)
	//fmt.Println(string(i))
	fmt.Println(op)
	/*
	for _,i := range op{
		fmt.Println(i.BlockNumber)
	}
	*/
}

func pr(){
	b1 := time.Now()
	{
	fmt.Println(time.Now())
	time.Sleep(500*time.Microsecond)
	b2:=time.Now()
	if(b2.Sub(b1)==2*time.Second){
		return
	}
	}
}

func testSleep(){
	//go pr()Format("15:04:05")
	b1 := time.Now()
	time.Sleep(2*time.Second)
	b2 := time.Now()
	fmt.Println(b1)
	b3 := b2.Sub(b1)
	if(b3 > 3*time.Second){
		fmt.Println("233")
	}
	fmt.Println(b3)
	time.Sleep(5*time.Second)
}

