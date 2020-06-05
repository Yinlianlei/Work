#include<iostream>
using namespace std;
class test
{
    private:
        int A;
        mutable int B;//可以使当接口被const限制不可修改成员数据时可以修改此数据
        static int mun;
    public:
        test(){A=3;B=4;};
        test(int AA,int BB)
        {
            A=AA;
            B=BB;
        };
        void show()
        {
            cout << A << " " << B << endl;
        };
        static void Plus()
        {
            mun++;
        };
        ~test()
        {
            //cout << mun << endl;
        };
        test& operator+(const test &);
};
test& test::operator+(const test &AA)//若声明为const前缀的则会导致只有CC1=AA+BB成立；
//虽说其他一个并没有成功改变值
{
    A+=AA.A;
    B+=AA.B;
    return *this;
}
int test::mun=0;
int main(void)
{
	//返回对象的说明
    test AA,BB(1,2),CC1,CC2,CC3;
    //AA.show();//这里只是回忆知识点

    //使用const引用的最常见原因旨在提高效率
    //返回对象将会调用构造函数，引用却不会
    //使用const引用版本效率更高
    //若参数列表中都为const类型，使用const类对象进行返回才更为匹配

    //常见的两种返回非const对象的情形
    //1-重载运算符
    //2-以及重载与cout一起使用的<<运算符
    BB.show();
    AA.show();
    CC1=AA+BB;//赋予两个类对象之和
    (AA+BB)=CC2;//无变化
    AA.show();//无变化
    CC1.show();
    CC2.show();
	return 0;
}
