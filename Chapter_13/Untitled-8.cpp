#include<iostream>
#include".h\Chapter_13.h"
using namespace std;
using namespace U_6;
int main(void)
{
	//模板的具体化
    //隐式实例化//编译器在需要对象前实不会生产类的隐式实例化
    //例如创建一个指针若不赋值则不会隐式实例化
    base<double> base1(3.2);
	//显式实例化
    //使用template进行声明
    //template class base<int>;//在头文件中声明用于声明为一个类

    //显示具体化
    //template<typename T>例如此  


	return 0;
}
