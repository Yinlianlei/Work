package main
import "fmt"

//函数书写func name(list)[return list]{}//可返回多个值

func hello(){
	fmt.Println("Hello world")
}

func swap(a,b string,c int)(string,string){
	a,b = b,a
	for i:=0;i<c;i++{
		println("Yinlianlei")
	}
	return a,b
}

func main(){
	hello()
	a,b,c := "Hello","world",2
	a,b = swap(a,b,c)
}
