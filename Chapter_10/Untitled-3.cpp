#include<iostream>
using namespace std;
class test
{
    private:
        int A;
    public:
        test()
        {
            A=3;
        };
        void show()
        {
            cout << A << endl;
        };
        friend test operator+(int &,const test &);
        //friend void operator<<(const ostream &,const test &);//对于test引用时友元//对于ostream是非友元
        friend ostream& operator<<(ostream &,const test &);
        //由于友元可能会出现参数列表相同而导致的二义性错误
        //因此有责转换和友元会解决此问题
};
ostream & operator<<(ostream &oc,const test &B)
{
    oc << B.A << endl << "YEs" << endl;
    return oc;//返回ostream&意味着该函数返回ostream对象的引用，即它自己
};
int main(void)
{
	test A;
	cout << A;//==opterator<<(cout,A);
	return 0;
}
