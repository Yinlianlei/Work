#include<iostream>
#include".h\Chapter_13.h"
using namespace std;
using namespace U_10;
//函数别名
typedef Base<string> BS;
//==
template<class T>
using BS_1 = Base<T>; //方便构建模板//若多个重复的模板参数可以如此进行简化
int main(void)
{
	//模板类和友元类
	//模板的友元类有三种
	//1-非模板友元
	//2-约束模板友元，即友元类下取决于类被实例化的类型
	//3-非约束模板友元，即友元的所有具体化都是类的每一个具体化的友元
	string A = "Yinlianlei", B = "Girl";
	Base<string> TXT(A,B);
	show(TXT);
	show1<string>();
	show2(TXT);

    BS_1<string> NS(B,A);//可行//编译器版本太老
    show(NS);

	return 0;
}
