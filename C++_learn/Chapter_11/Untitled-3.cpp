#include<iostream>
#include".h\Chapter_11.h"
using namespace std;
int main(void)
{
	//空指针
    char * C=new char[11]{"Yinlianlei"};//可行
    //C=NULL;//C的宏定义
    //C=nullptr;//C++11引入的新的解决方案
    
	//技巧：使用strcmp()在重载运算符内进行运算，可以是结果简化

    test2 ll(C,6);
    cout << ll[6-1] << endl;//可以凭借重载运算符访问私有数据
    ll.show();
    ll[5]='p';//由于是采取引用的方法，所以赋予的返回值指向源地址，然后赋值可以起到修改的作用
    ll.show();
	return 0;
}
