package main

import "fmt"

func main(){
	//逻辑判断
	a:=true
	if a == true{
		fmt.Println("Yinlianlei")
	}else{
		println("YinSuo")
	}
	b:=4
	switch{
		case b==1:
			println(b)
		case b==4:
			println(b)//fallthrough 会强制执行后面的 case 语句
			fallthrough
		case b==3:
			println(b+22)
		default:
			println(b)
	}
	//select 是 Go 中的一个控制结构，类似于用于通信的 switch 语句。每个 case 必须是一个通信操作，要么是发送要么是接收。
	var aa,bb chan int
	var aaa,bbb int
	select{
	case aa <-aaa:
		println("233")
	case bb <-bbb:
		println("332")
	default:
		println("2332")
	}
}

