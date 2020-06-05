#include<iostream>
#include".h\Chapter_9.h"
class test
{
	private:
		int A;
	public:
		test(int B)
		{
			A=B;
		};
		int SA()
		{
			return this->A;//this指针代表此类对象加上->引用成员
		};
};
//每个成员函数都有一个this指针，this指向调用对象
//引用整个调用对象，使用表达式*this//即类的地址就是*this，而this指向类地址
using namespace std;
int main(void)
{
	//this指针
	test A(2);
	int B=A.SA();
	cout << B << endl;
	return 0;
}
