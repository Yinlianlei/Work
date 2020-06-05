#include<iostream>
#include<list>
#include<array>
#include<algorithm>
#include<functional>//提供了多种自定义模板类对象
#include"Chapter_15.h"
using namespace std;
using namespace U_8;
int main(void)
{
	//函数对象(函数符)
	//可以使用函数方式与()结合使用的任意对象。(包括函数名，指向函数的指针和重载了()运算符的类对象)
	Test A("Yinlianlei",1);
	string name = ".sss";
	string B = A(name);//此处重载了A的()运算符
	cout << B << endl;

	//for_each()第三个参数便是函数符，其通过模板解决了兼容问题

	//函数符概念
	//生成器是不用参数便可调用函数符
	//一元函数是用一个(函数)参数可以调用的函数符
	//二元函数是用两个(函数)参数可以调用的函数符

	//一些STL函数需要谓词参数(或二元谓词参数)
	//返回bool值的一元函数是谓词
	//返回bool值的二元函数是二元谓词

	list<int> tmp1(10, 2);
	*tmp1.begin() -= 3;
	tmp1.remove_if(IS_DONE);
	//若为true则会删除//此方式将谓词用作参数//也可以将类的()运算符重载后调用其中
	for_each(tmp1.begin(), tmp1.end(), show);
	cout << endl;

	//预定义的函数符
	//STL提供基本函数符是为了更好支持将函数作为参数的STL函数
	double AA[4]{ 1,4,9,16 };
	double BB[5]{ 16,9,4,1,100 };
	vector<double>tmp2(AA, AA + 4);
	vector<double>tmp3(BB,BB+4);
	transform(tmp2.begin(), tmp2.end(), ostream_iterator<double, char>(cout, " "), AK_12);
	cout << endl;//将迭代器区域内的数据交予AK_12处理后再由第三个函数处理
	transform(tmp2.begin(), tmp2.end(), tmp3.begin(), ostream_iterator<double, char>(cout, " "), AA_12);
	cout << endl;//第二个重载有五个参数，第三个为第二个迭代器的起始位置，所取长度由第一二个参数决定，若第三个参数的长度小于所需要的长度则会导致打印出来的数字是乱码

	//functional头文件提供的plus<>()可以完成常规的相加运算
	plus<int> EDD;
	int C = EDD(AA[0], BB[0]);//作为STL函数的参数会很方便
	cout << C << endl;

	//算术符对应函数符
	//+		plus
	//-		minus
	//*		multiplies
	///		divides
	//%		modelus
	//-		nagete
	//==	equal_to
	//!=	not_equal_to
	//>		greater
	//<		less
	//>=	greater_equal
	//<=	less_equal
	//&&	logical_and
	//||	logical_or
	//!		logical_not

	//自适应函数符和函数适配器
	//STL五个相关概念：自适应生成器，自适应一元函数，自适应二元函数，自适应谓词，自适应二元谓词
	//携带自适应原因：携带了标示参数类型和返回类型成员，分别为：result_type，first_argument_type，second_argument_type
	//意义：函数适配器对象可以使用函数对象并认为存在这些成员

	//bind1st和bind2nd可以将自适应二元函数转化为自适应一元函数
	//设f2(X,Y);bind1st(f2,Z)f1(Q)==f2(Z,Q);
	vector<double>tmp4(BB, BB + 5);
	transform(tmp4.begin(), tmp4.end(), ostream_iterator<double, char>(cout, " "), bind1st(minus<double>(), 3));//minus后加()使用默认构造函数
	//==3-*tmp4
	cout << endl;




	return 0;
}
