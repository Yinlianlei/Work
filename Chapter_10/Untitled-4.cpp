#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
class test
{
	public:
		enum te{mode1,mode2};//用于外部选择模式//还可以在默认函数中加上默认模式
	private:
		int A;
		int B;
		te et;//状态成员//用于表示成员函数所需要的形式
	public:
		test(int AA,int BB)
		{
			A=AA;
			B=BB;
			et=mode1;
		};
		test(int AA)
		{
			A=AA;
			B=AA;
			et=mode2;
		}
		void ts();
		void sst(te A);
};

void test::sst(te A)
{
	double tmie;
	srand(time(0));
	tmie=rand()%2000;//随机数字
	cout << tmie << endl;
};
void test::ts()
{
	if(et==mode1)//判断所需要那种形式
	{
		cout << A << endl << B << endl;
	}
	else if(et==mode2)
	{
		cout << A << endl << B << endl;
	}
	else
	{
		cout << "ERROE" << endl;
	}
}
int main(void)
{
	//矢量类
	test A1(1,2),A2(3);
	A1.ts();
	A2.ts();
	A1.sst(test::mode1);//传递数字无法转换为枚举类型
	//必须如此使用枚举，不能使用test::te(0)等；

	//几元运算符表示着有几个操作数
	return 0;
}
