package main
import "fmt"

func main(){
	//循环
	for i:=0;i<10;i++{
		fmt.Println("Yinlianlei") 
	}
	var strings = []string{"Yinlianlei","233"}
	for i,j:=range strings{//可以对字符串、数组、切片等进行迭代输出元素。
		println(i,j)
	}
}
