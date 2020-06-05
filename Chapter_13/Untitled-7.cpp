#include<iostream>
#include".h\Chapter_13.h"
using namespace std;
using namespace U_5;
int main(void)
{
	const char *A = { "Yinlianlei" };
	base<const char* > test(A);//用于调用一个指针用于内部指针操作
	test.show();

	int MA[4]={1,2,3,4};
	string name="Yinlianlei";
	STD<string,4> B(name,MA);//其中4式赋予非类型参数(表达式参数)
	B.show();
	//模板类若是作为成员类(组件类)则会使实例化基类包含成员类，例base<STD<int,4>>

	//可以使用模板来进行使用递归//注意分配空间而不是空指针
	base< base<int> > CC;
	for(int D=0;D<3;D++)
	{
		for(int E=0;E<3;E++)
		{
			CC[D][E]=(E+1)*(D+1);
		}
	}
	for (int D = 0; D < 3; D++)
	{
		for (int E = 0; E < 3; E++)
		{
			cout << CC[D][E] << " ";
		}
		cout << endl;
	}
	//使用两个类型的参数，即两个模板参数template<class t1,class t2>

	

	return 0;
}
