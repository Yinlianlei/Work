#include<iostream>
#include<new>
using namespace std;
int main(void)
{
	//定位new运算符
    //一般情况下，new会在堆当中找到合适的内存块并分配，然后又编译器在栈上记录着变量名
    //定位new运算符可以指定使用的位置，可以以此设置内存管理规程
    //处理需要通过特定地址进行访问的硬件或在特定位置创建对象
    char XS[30];
    int *A=new (XS) int [3];//从XS中分配空间给A数组
    int *B=new (XS+3*sizeof(int)) int ;//在XS的基础上向右偏移三个单位的int

    cout << (void *)XS << endl;//若不加上(void *)则会导致输出的是字符串

    //delete [] A;//delete只能用于常规new运算符分配的堆内存，不能用于此（A用的是静态内存）
    //若XS也是分配内存的变量，则可以使用delete释放内存块

    
	
	return 0;
}
