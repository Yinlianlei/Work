#include<iostream>
#include".h\Chapter_11.h"
using namespace std;
int main(void)
{
    test A(8),B(6);
    B.NEW("Yinlianlei");
    A.NEW("SHOW");
    A=B;//复制构造函数//字符串貌似不能复制，推测原因，内存大小不同，默认不复制
    //==test A=test(B);
    //此时的构造函数类型为test(const test &);
	for(int AA=0;AA<3;AA++)
    {
        A.Show();
    }//此处无事发生
    //类对象如果作为参数被调用会导致析构函数被调用
    return 0;
    //系统存在保护错误(GPF)，禁止它访问被禁止访问的内存单元
}
