#include<iostream>
#include".h\Chapter_9.h"
using namespace std;
//定义类：类规范包括两类：类方式定义，类声明
//接口：共享框架，供及其与机器之间或人与机器之间交互使用
//接口让程序员能够编写与类对象交互的代码，从而能够让程序使用类对象

int main(void)
{
	//oop特性：
    //抽象，封装和数据隐藏，多态，继承，代码的可重用性
	test_1 A;//每个对象都有自己的储存空间用以储存内部变量和类成员
    A.CIN();
    A.show();
    //类设计目标：尽可能将共有接口和实现细节分开
    //数据隐藏是一种封装，将实现部分隐藏在私有部分
    //不仅可以防止直接访问数据，还可以让开发者(类的用户)无需了解数据是怎样表示的

    //细节与接口分离可以编译细节修改时无需修改接口而时程序维护简单
	return 0;
}


