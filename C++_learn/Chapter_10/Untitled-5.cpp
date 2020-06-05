#include<iostream>
using namespace std;
class test
{
    private:
        int A;
        int B;
    public:
        test()
        {
            A=3;
            B=4;
        }
        explicit test(int AA,int AB)//若给予第二个值初始值，则会使只用一个初始值的隐式初始化成立
        {
            A=AA;
            B=AB;
        }
        /*explicit*/ test(int C)//若加上explicit则会成为强制类型转换//只能显示转换
        {
            A=C,B=C;
        };//加上explicit是为了防止因为意外写出test A=3;导致调用隐式转换将原值覆盖的方式
        void show()
        {
            cout << A << " " << B << endl;
        };
};
int main(void)
{
	//类的自动转换和强制类型的转换
    test A,B,C;
    B=3;//隐式转换，逐成员进行赋值，此适用于test(int C)类型
    //explicit将关闭此隐式转换，但是仍然允许显示转换（强制类型转换）
	C=test(4);//==C=(test) 4;
    //注意：只接收一个参数的构造函数定义了从参数类型到类类型的转换，若使用explicit则会使其只能接受显式转换
    B.show();
    A.show();
    C.show();
    /*
    何时使用类强制转换：
    1-类对象初始化其他类型的变量时；
    2-将其他类型变量赋予类对象时；
    3-将其他类型的值传递给接受类参数的函数时
    4-上述情况中，使用可转换为都变了类型的内置类型时
    //前提：无二义性
    */
	return 0;
}
