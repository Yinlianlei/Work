#include<iostream>
using namespace std;
class test
{
	private:
		double AA;
		double BB;
	public:
		test(double A,double B)
		{
			AA=A;
			BB=B;
		}
		test(){AA=0;BB=0;};
		test(double A){AA=A;BB=A;};
		void show()
		{
			cout << AA << endl;
		}
		friend test operator+(const test &,const test &);
};
test operator+(const test &A,const test &B)
{
	test tmp;
	tmp=A.AA+B.AA;
	return tmp;
};
int main(void)
{
	//需要将单个值转换为类类型，需要构建转换的构造函数
	test Aw(3,4);
	double Do=3.2;
	(Do+Aw).show();//此处Do被隐式转换为了test类
	//可以加上explicit关键词，防止隐式转换
	return 0;
}
