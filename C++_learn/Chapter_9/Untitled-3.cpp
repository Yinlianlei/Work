#include<iostream>
#include<string>
#include".h\Chapter_9.h"
using namespace std;
//what::what(){};//类构造函数的默认构造函数

int main(void)
{
	//类构造函数//将值赋予数据成员
    //构造函数没有数据类型
	//类成员名不能用于构造函数的参数名//够找函数的参数不是类成员而是赋予成员的值

    //显式使用
    what T1 = what();
    //隐式使用
    what T2 ();//目前不清楚如何使用
    //创建和new一起使用的办法
    what *T3 = new what();//此不会调用析构函数

    //只有当没有任何构造函数时，编译器才会踢狗默认构造函数
    //对象时可以通过等会创建临时对象的

    //析构函数//当函数过期时自动调动
    what::what();
    T4://另外一种声明方法
    what T4 = what();

    //可以列表初始化
    //例：what T5 = {1,2,3};//假设有三个参数
    
    //可在函数原型后加蛇const使之无法修改参数
    T1.show();
	return 0;
}

what::what()//构造函数必须在类定义中声明
{
    name="Yinlianlei";
    math=1;
    cout << name << endl;
}

what::~what()//析构函数
{
    cout << "Bye bye." << endl;
}

/*
Yinlianlei 1
Yinlianlei 2
Yinlianlei 3
Yinlianlei 4
Bye bye.4
Yinlianlei 6
Bye bye.6
Bye bye.2
Bye bye.1


此处是函数原型为:waht(int A)中的结果
*/
