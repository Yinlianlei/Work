#include<iostream>
#include"Chapter_12.h"
using namespace std;
using namespace U_2;
int main(void)
{
	//is-a关系
	//is-a-kind-of继承，术语是is-a
	//共有继承的最常用方式
	//派生类也是一个基类对象//可以对基类对象执行任何操作，也可以对派生类对象执行

	//C++种可以建立has-a，is-implemented-as-a(用什么来实现)，uses-a关系

	//两种实现多态公有继承的方式：派生类中重新定义基类的方法，使用虚方法

	//is-a的关系通常为单向A->B

	//virtual关键字可以使根据引用或者指针-指向的对象的类型-选择方法
	//通常为根据引用或指针类型选择
	test A("Yinlianlei", 3),AA("LinghuMing",5);
	test_1 B(4,A);
	test& C = A;
	test& D = B;
	C.show();//调用的是A.show()
	D.show();//调用的是B.show()
	//std::string name = "YinQingfeng";
	//int nm=3;
	test* E[2];
	E[0] = new test("Yinlianlei", 3);
	E[1] = new test_1(3, AA);
	E[0]->show();
	E[1]->show();//即可指向test类，也可指向test_1类
	return 0;
    //多态性：使用一个数组来表示多种类型的对象
    //比如上，由于test是test_1的基类，因此指针可以指向test对象也可以指向test_1的对象

}

    