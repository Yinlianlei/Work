#include<iostream>
using namespace std;
class test
{
    private:
        double A;
        double B;
    public:
        test operator+(double) const;
        friend test operator+(const test &,const test &);
        test()
        {
            A=3.2;
        };
        operator double()const
        {
            return double(A);
        };
};
test test::operator+(double B) const//提供test+double类型的原型//依赖于隐式转换//更加占有内存
{
    test AA;
    AA.A=A+B;
    return AA;
}
test operator+(const test &A,const test &B)//提供double+test类型的原型//显示匹配类型的函数
{
    test AA;
    AA.A=A.A+B.A;
    return AA;
}
int main(void)
{
	//转换函数和友元函数
	double A=3,total2;
    test B,total1;
    total1=B+A;
    total2=A+B;
    cout << total1 << " " << total2 << endl;
	return 0;
}

/*
#include<iostream>
using namespace std;
class test
{
private:
	double A;
	double N;
public:
	test(double B) { A = B; N = 90; };
	test operator+(double) const;
	friend test operator+(const test&, const test&);
	test()
	{
		A = 3.2;
		N = 90;
	};

	//operator double()const
	//{
	//	return double(N);
	//};

	void ss()
	{
		cout << A;
	};

};
test test::operator+(double B) const//提供test+double类型的原型//依赖于隐式转换//更加占有内存
{
	test AA;
	AA.A = A + B;
	return AA;
}

test operator+(const test& A, const test& B)//提供double+test类型的原型//显示匹配类型的函数
{
	test AA;
	AA.A = A.A + B.A;
	return AA;
}

int main(void)
{
	//转换函数和友元函数
	double A = 3, total2;
	test B, total1, tmp;
	total1 = B + A;
	//total2 = A + B;
	(A + B).ss();
	(B + A).ss();
	//cout << total2 << endl;
	tmp.ss();
	return 0;
}

*/
