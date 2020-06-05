#include<iostream>
using namespace std;
class test
{
private:
	int A[3];
	int B[3];
	int sum;
public:
	test()
	{
		A[0] = 3, A[1] = 4, A[2] = 5;
		B[0] = 3, B[1] = 4, B[2] = 5;
		sum = 6;
	};
	test(int AA[3], int BB[3])
	{
		A[0] = AA[0], A[1] = AA[1], A[2] = AA[2];
		B[0] = BB[0], B[1] = BB[1], B[2] = BB[2];
		sum = 0;
		for (int C = 0; C < 3; C++)
		{
			sum += A[C] + B[C];
		}
	};
	test operator+(const test& A) const
	{
		test sum;
		sum.sum = 0;
		for (int BC = 0; BC < 3; BC++)
		{
			sum.sum += A.A[BC] + A.B[BC];
		}
		return sum;
	};
	void show()
	{
		cout << sum << endl;
	};
};
int main(void)
{
	//运算符重载    
	int A[3] = { 1,1,1 };
	int B[3] = { 0,0,0 };
	test ts,st;

	test AA(B,A), BB(A, B);
	ts = AA.operator+ (BB);//其中一种使用opterator的方式
    st=AA+BB;//另外一种使用方法
    st=AA.operator+(BB.operator+(BB));
    //其他计算符号也可以进行其他计算，甚至可以多个一起计算
	//也可重载其他运算符
	AA.show();
	BB.show();
	ts.show();
    st.show();
	//重载限制
    //1，重载后的运算符必须至少有一个操作数使用户自己定义的
    //2，使用运算符是不能违背运算符原来的语句规则，不能修改优先级
    //3，不能创建新的运算符
    //4，不能重载一些运算符
    /*
    sizeof  sizeof运算符
    .       成员运算符
    .*      成员指针运算符
    ::      解析运算符
    ?:      条件运算符
    typeid  一个RTTI运算符
    const_cast  强制类型转换运算符
    dynamic_cast   强制类型转换运算符
    reinterpret_cast    强制类型转换运算符
    static_cast 强制类型转换运算符
    */
	//5，以下函数只能通过成员函数进行重载
    /*
    =   赋值运算符
    ()  函数调用运算符
    []  下标运算符
    ->  通过指针访问类成员的运算符
    */
	return 0;
}
