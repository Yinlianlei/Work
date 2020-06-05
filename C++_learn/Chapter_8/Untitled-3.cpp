#include<iostream>
using namespace std;
static void test_1();
extern void test_2();
int main(void)
{
	//函数的链接性为默认为外部
    //可以在函数原型中使用关键字extern来指出函数是在另一个文件中定义的//可选
    //也可使使用static使之称为内部函数
	
    test_1();
    test_2();//可行
	return 0;
}

//定义静态函数会将覆盖掉同名的外部函数
//函数定义规则对于每个非内联函数，程序只能包含一个定义，对于函数来说只有一个文件可以包含此函数的定义
//使用函数必须声明函数原型
//内联函数不受函数定义规则限制，同一个函数的所有内敛定义都必须相同

//C++寻找函数定义的先后顺序：静态函数->外部文件->函数库
//外部文件中的函数必须只有一个，否则直接报错

//语言连接性：对于函数的名称进行转换，以方便重载时分辨，例如spaf转化为spaf_i(C++中)
//指定连接程序：
//extern "C" void st()//C语言风格的转换
//extern void st()//默认指出
//extern "C++" void st()//C++风格的转换

static void test_1()//此函数尽在此文件中可见
{
    cout << "YES";
}
