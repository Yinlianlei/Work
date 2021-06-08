package main

import (
	"./sql"
	"fmt"
)

func main(){
	//fmt.Println(sql.Sql_Huawei_Login("ljz","cqu"))
	//fmt.Println(sql.Sql_Huawei_SearchFid("233"))
	//fmt.Println(sql.Sql_Huawei_CheckEvi("",""))
	//fmt.Println(sql.Sql_Huawei_GetFid("666","20191739","ljz","cqu","ry","Internet",1))
	fmt.Println(sql.Sql_Huawei_Register("ljd",18,"PSnake",1,"tuna"))
}