package main
import "fmt"

func main(){
	var a uint8 = 233 //go语言支持的类型uint8-uint64,int8-int64,float32-float64,complex64-complex128,byte,rune,string,bool
	//声明变量方式var name type
	fmt.Println(a)
	var s string = "Yinlianlei"
	fmt.Println(s)
	var ss,sss string = "Hello,","world"//多个变量的声明方式
	ss = "hello,"
	sss = "world"
	fmt.Println(ss,s)
	fmt.Println(ss,sss)
	fmt.Printf("%d %s %s %s\n",a,ss,sss,s)//printf精细操作
	Yin:="2332"//自动识别变量类型的方式
	fmt.Println(Yin)
	Yin,sss = sss,Yin//exchange
	fmt.Println(Yin,sss)
}
