#include<iostream>
using namespace std;
class test
{
private:
	double A;
	double B;
public:
	test()
	{
		A = 8;
		B = 4;
	};
	void show()//成员函数
	{
		cout << A << "\t" << B << endl;
	};
	friend test operator*(double, const test&);
	//test operator*(double,const test &)为非成员函数
	//test operator*(double,const test &);//类里声明会显示参数过多
};
test operator*(double A, const test& B)//友元的声明//友元必须在相应的类中才能够调用相关的数据成员
{
	test tmp;
	tmp.A = A * B.A;
	tmp.B = A * B.B;
	return tmp;
}

int main(void)
{
	//友元
	//分类：友元函数，友元类，友元成员函数
	//可以让函数成为类的友元
	test tmp, B;
	tmp = 2.5 * B;//一般左边为操作数//这样就可以直接调用类里面的私有数据
    //达到扩宽接口的作用
	tmp.show();
	return 0;
}
