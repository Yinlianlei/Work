#include<iostream>
#include".h\Chapter_8.h"
using namespace std;
int main(void)
{
	//单独编译
	int A,B,C;
	Time D;
	cout << "INPUT";
	while(!(cin >> D.hour >> D.min >> D.sec))
	{
		ERROR_CHANGE();//作用域为此花括号内
	}
	cout << D.hour << ":" << D.min << ":" << D.sec;
	//连接性：外部的名称可以在文件建共享
	//连接线为内部的名称只能由一个文件中的函数共享

	//自动变量的作用域为局部，静态变量的作用域是局部还是全局取决于定义
	//C++中函数的作用域可以是整个类或者名称空间，但是不能是局部的

	return 0;
}
