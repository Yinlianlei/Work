#include<iostream>
#include<memory>
#include"Chapter_15.h"
using namespace std;
using namespace U_3;
int main(void)
{
	//unique_ptr为何要由于auto_ptr
	auto_ptr<int> A1(new int(1));
	auto_ptr<int> A2;
	//A2=A1;//此处会将A1的地址所有权交给A2
	//且两个的析构函数会试图删除同一个地址两次，会使程序报错
	//而unique_ptr则会在编译阶段直接报错

	unique_ptr<string> Name(new string);
	string name = "Yinlianlei";
	Name = Deemo(name.c_str());//此处返回一个unique_ptr<string>对象，且此对象会在返回后销毁
	cout << *Name << endl;
	//若unique_ptr想象上面auto_ptr一样交换的话std标准库里有move()函数供unique_ptr进行赋予

	unique_ptr<string> tmp;
	tmp = move(Name);
	cout << *tmp << endl;
	
	
	


	return 0;
}
