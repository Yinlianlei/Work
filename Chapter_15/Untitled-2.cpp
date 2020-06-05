#include<iostream>
#include<string>
#include"Chapter_15.h"
using namespace std;
using namespace U_2;
int main(void)
{
	//智能指针模板
	//三种类型，auto_ptr，unique_ptr，shared_ptr
	//智能指针可以将new获得的地址付给对象，当智能指针过期时会用delete来释放来至堆的内存
	double tmp1;
	cout << "INPUT:" << endl;
	cin >> tmp1;
	tmp1=test(tmp1);
	cout << tmp1 << endl;
	
	//声明方式二
	auto_ptr<double> tmp2;
	double* tmp3 = new double;
	tmp2 = auto_ptr<double>(tmp3);
	cin >> *tmp3;
	cout << *tmp3 << endl << *tmp2 << endl;

	//auto_ptr有个问题即会造成内存空间的多次delete, 即将一个智能指针的地址赋予另一个智能指针
	//解决方式：
	//1-定义赋值运算符，2-建立所有权概念(特定对象只能在一个智能指针拥有unique_ptr也是用这个概念)，3-创建智能更高的指针
	
	shared_ptr<double> tmp4[2]
	{
		shared_ptr<double>(new double(1.1)),
		shared_ptr<double>(new double(2.2))
	};
	shared_ptr<double> tmp41;
	tmp41 = tmp4[0];

	for (int A = 0; A < 2; A++)
	{
		cout << *tmp4[A] << endl;
	}
	cout << *tmp41 << endl;

	return 0;
}

