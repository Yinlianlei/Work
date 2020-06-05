#include<iostream>
using namespace std;
template<typename Type>
class Yin
{
    public:
        Type name;
        Yin(Type A):name(A){};
        void Show(){cout << 233 << endl;};
};

template<template <typename T > class T1>
class YinL
{
    private:
        T1<string> name;
        T1<string> sex;
    public:
        YinL(){name="NULL";sex="BOY";};
        YinL(string A,string B):name(A),year(B){};
        void show(){cout << name << "\t" << sex << endl;};
};

template<class T1>
class base
{
    private:
	    template<class T2>
	    class STD
	    {
	        private:
		        T2 A;
	    public:
	        STD() { A = 0; };
		    STD(T2 B) :A(B) {};
		    void show();
	    };
	    T1 name;
	    STD<T1> CY;//注意声明模板格式
    public:
	    base() { name = 0; };
	    base(T1 A, T1 B) :name(A), CY(B) {};
	    void show()
	    {
		    CY.show();
		    cout << name << endl;
	    }
};
template<class T1>
template<class T2>//此处模板是嵌套的，不能使用template<class T1,class T2>
void base<T1>::STD<T2>::show()//定义模板成员的方式
{
	cout << A << endl;
};
int main(void)
{
	//成员模板
	//模板可以作为结构，类或者模板类的成员，即可以完全实现STL模板
	base<string> A("Yinlianlei", "Vyvyan");

	A.show();
    //同时也可以用其他模板作为参数进行运算
    YinL<Yin> BB("Yinlianlei","Girl");
    BB.show();

	return 0;
}


/*
//关于类模板作为参数有问题，如何调用使用类模板参数后的数据
#include<iostream>
using namespace std;
template<typename Type>
class Yin
{
public:
	Type name;
	Yin(Type A) :name(A) {};
	void Show() { cout << 233 << endl; };
};

template<template <typename T > class T1>
class YinL
{
private:
	T1<string> name;
	T1<string> sex;
public:
	YinL() { name = "NULL"; sex = "BOY"; };
	YinL(string A, string B) :name(A), sex(B) {};
	void show();
};
template<template <typename T > class T1>
void YinL<T1>::show()
{
	cout << name << "\t" << sex << endl;
};


int main(void)
{
	//同时也可以用其他模板作为参数进行运算
	YinL<Yin> BB("Yinlianlei", "Girl");
	BB.show();

	return 0;
}

*/
