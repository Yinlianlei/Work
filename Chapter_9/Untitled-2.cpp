#include<iostream>
#include".h\Chapter_9.h"
using namespace std;
int main(void)
{
	cout.setf(ios_base::fixed,ios_base::floatfield);
    cout.precision(1);
    double A=3.30;
    cout << A << endl;
    Showpoint(A);
    cout << A << endl;	
	return 0;
}

//oop特性：抽象，封装，数据隐藏

/*
template<typename A>
A Showpoint(A B)
{
    ios_base::fmtflags orig = cout.setf(ios_base::fixed,ios_base::floatfield);
    //fmtflags是ios_base中的一种类型//orig记录了所有标记，用于重置(仅用于h文件中)
    streamsize prec = cout.precision(3);
    cout.setf(orig,ios_base::floatfield);
    cout.precision(prec);
}
*/



