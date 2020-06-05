#include<iostream>
using namespace std;
int main(void)
{
	//储存方案和动态分布
    int *A=new int [3] {1,2,3};//动态内存//不是LIFO后进先出//初始化数组
    int *B=new int (3);//初始化指针//单个元素用括号，多个用花括号
    //通常编译器使用三块内存：一块静态变量，一块自动变量，一块动态储存
    //有意外情况会导致内存无法在使用完后自动释放

    struct ss{int A;int B;};
    ss *S=new ss {1,2};//结构进行初始化


	delete [] A;
	return 0;
}
