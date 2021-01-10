package main
import "fmt"
//常量可以用len(), cap(), unsafe.Sizeof()函数计算表达式的值
import "unsafe"
const(
	name="Yinlianlei"
	lens=len(name)
	sizei=unsafe.Sizeof(name)
)//enum

/*
ota，特殊常量，可以认为是一个可以被编译器修改的常量。
iota 在 const关键字出现时将被重置为 0
*/
const(
	aa=iota
	bb
)

func main(){
	//常量//只可以是布尔型、数字型（整数型、浮点型和复数）和字符串型。
	const s int = 233
	fmt.Println(s)
	const he,wo string = "hello","world"
	fmt.Println(he,wo)
	const a,b,c = true,332,"ss"//const可以多个不同类型变量一起赋值
	fmt.Println(a,b,c)
	println(a,b,c)
	println(name,lens,sizei)
	println(aa,bb)
}
