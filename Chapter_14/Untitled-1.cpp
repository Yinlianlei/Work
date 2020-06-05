#include<iostream>
#include"Chapter_14.h"
using namespace std;
using namespace U_1;
int main(void)
{
	//友元类
	//友元类可以访问原始类的私有成员和保护成员
    //提高了程序的灵活性

	Test_2 B;
	Test_3 A("Yinlianlei");
	A.show(B);

	Test_4 C;
	Test_5 D;
	show(C,D);
	show(D,C);


	return 0;
}
