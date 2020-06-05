#include<iostream>
using namespace std;
//一个声明空间中的名称不会与另外一个名称空间的相同名称发生冲突
//同时允许程序的其他部分使用该名称中的声明的东西
//全局名称空间，对应文件级的声明区域
namespace test //不能位于代码块中
{
    int tes_1=1;
    string nema="Yin";
    namespace test_2
    {
        int tes_1=3;
        string nema="lei";//可以位于一个名称空间中//套娃
    }
}
namespace test_1
{
    int tes_1=2;
    string nema="lian";
    void ns()//也可以添加函数并定义//也可以扔在其他文件里定义
    {
        cout << "OK" << endl;
    };
}
int main(void)
{
	//名称空间
    //为了解决名称冲突问题而设计//必须熟悉的术语：
    //声明区域
    //潜在作用域：从声明点开始到声明区域结尾
    //作用域：变量对于程序可见的范围
    int tes_1=3;
    cout << test::nema << test_1::nema << test::test_2::nema;
    //调用需要::解析运算符进行
    
    cout << tes_1 << endl //未被修饰的名称，即未限定的名称
        << test::tes_1 << endl;//被修饰的名称，即限定的名称

    
	
	return 0;
}
