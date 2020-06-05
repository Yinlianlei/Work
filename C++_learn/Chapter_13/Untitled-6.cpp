#include<iostream>
#include".h\Chapter_13.h"
using namespace std;
using namespace U_4;
int main(void)
{
	//类模板
	//模板提供参数化类型->能够将类型名作为参数传递给接收方来建立函数

    int A=3;
    string name="Yinlianlei";
    base<string> test(name,A);
    //函数实例化或具体化//必须用<>请求指定实例化

    test.show();

    //指针栈能够使用模板指针
    //注意：若只是创建指针而没有分配空间式没有用的，必须分配空间且注意调用格式
	return 0;
}
