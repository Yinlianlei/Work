#include<iostream>
using namespace std;
class test
{
    private:
        double A;
    public:
        test()
        {
            A=3.2;
        };
        test(double AA)
        {
            A=AA;
        };
        void show()
        {
            cout << A << endl;
        };
        operator int()const;//此处将会是四舍五入//但是好像不对劲
        operator double()const;//转换函数//此处指明
        /*
        格式：operator typename();
        1-转换函数必须时类方法
        2-转换函数不能指定返回类型
        3-转换类型不能有参数
        */
};
test::operator double() const 
//也可使用double test_doub(){return double(A*3);};代替
//但是将会成为隐式转换且不能使用double B=test A;
{
    return double(A*3);
};
test::operator int()const
{
    return int(A);
};
int main(void)
{
	//转换函数
    //隐式转换：程序自动转换称为隐式转换(编译器完成的)
    //显示转换：程序员自主强制转换

    //C++提倡使用显示转换而非隐式转换
    test A(5.9);
    double B=double(A);//指定强制转换double
    int C=A;
    cout << B << " " << C << endl;
    //C++提高下面类型转换
    //1-只有一个参数的类构造函数用于将类型于该参数相同的值转换为类类型，例：int参数传递给test类，将会被转换为test类
    //2-被称为转换函数的特殊类成员运算符函数
    //转换函数时类成员，没有返回类型，没有参数，名为operator typename()
    //将类对象赋予typename变量或将其强制转换为typename类型时，该转换函数将会自动调用
	return 0;
}
