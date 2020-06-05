#include<iostream>
using namespace std;
class test
{
    private:
        string A;
    public:
        test()
        {
            A="Yinlianlei";
        };
        test(string B)
        {
            A=B;
        };
        void show();
        ~test()
        {
            cout << "Complete" << endl;
        };
};
void test::show()
{
    cout << A << endl;
};
int main(void)
{
	char *C=new char [40];
	{
        test *P,*PO;
        P=new (C) test;//将内存空间置于C变量分配的空间中
        PO=new (C+sizeof("Yinlianlei")) test;//偏移
        P->show();
        PO->show();
        //delete PO;//释放内存一次释放一个，同时结束类对象周期，使之使用析构函数
        //delete P;
        P->~test();//由于delete释放了常规运算符的内存块，但是并未定位new运算符在该内存块种创建的对象调用析构函数
        PO->~test();//这样可以显示显示出析构函数(显式调用)
        delete [] C;
    }
    //但是这样就会出现一个尴尬的情况：C的内存空间会被释放
	return 0;
}
