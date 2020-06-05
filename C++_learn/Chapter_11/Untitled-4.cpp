#include<iostream>
using namespace std;
class test
{
    private:
        int A;
        static string B;
        char *C;
    public:
        void show(int D){A=D;cout << C << " " <<A <<endl;}; 
        static void show()
        {
            cout << "Yinlianlei" << B << endl;
        };
        friend istream & operator>>(istream &is,test & B);
        ~test(){delete [] C;cout << "Complete.\n";};
};

istream & operator>>(istream &is,test & B)
{
    char *tmp=new char [41];
    cout << "INPUT,is:";
    is.get(tmp,40);
    delete [] B.C;//用于清空内存，以便重新储存
    B.C=new char [strlen(tmp)+1];
    if(is)//if条件下如果达到文件尾或者读取到的是一个空行将会导致失败，is设置为false
        B.C=tmp;
    while(is && is.get()!='\n')
        continue;
    return is;
};
string test::B=" Show my home."; 
int main(void)
{
	//静态成员函数
    //静态成员函数无法通过对象调用，也不能使用this指针
	//若为公开声明，则可以用类名和解析运算符调用
    test::show();//例如

    //静态成员函数智能使用静态数据成员而不能于特定的对象相关联
    //静态成员函数设置类级，以控制类接口行为

    test AA;
    cin >> AA;
    AA.show();
    AA.show(3);

    //构造函数中使用new和delete，一般在构造函数new来初始化指针成员，在析构函数是使用delete
    //new和delete必须兼容，new相对于delete，new[]相对于delete[]
    //如果又多个构造函数，则必须以相同的方式使用new，要么都带中括号，要么都不带
    //只有一个析构函数所有的构造函数都必须和他兼容
    //但是可以在给猴枣函数中使用new初始化指针，而在另一个构造函数中将指针初始化为空(0,NULL,nullptr)
    //delete可以用于空指针

    //复制构造函数
    //默认是逐成员赋值
    //若是需要从一个类对象复制给另一个类，需要使用赋值构造函数和赋值构造函数
	return 0;
}
