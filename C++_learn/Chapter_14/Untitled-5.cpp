#include<iostream>
#include<typeinfo>
#include"Chapter_14.h"
using namespace std;
using namespace U_5;
int main(void)
{
	//RTTI(仅适用于包含虚函数的类)
    //运行阶段类型识别
    //有三个支持RTTI的元素：
    //dynamic_cast运算符使用一个指向积累的指针来生成一个指向派生类的指针，否则返回空指针
    //typeid运算符返回一个指出对象的类型的值
    //type_info结构储存了有关特定类型的信息

    //1-dynamic_cast运算符
    //能够反应是否可以安全的将对象的地址赋予特定类型的指针
    test_2* P2=new test_2;
    base* P1;
    try    //同时dynamic_cast将会引发一个bad_cast的异常(在头文件typeinfo中定义)
    {
        if(P1=dynamic_cast<test_2*>(P2))//这样可以使得程序的以判断
        {   //指针P2是否可以安全的转换为test_2*得指针
            //若可行则会返回一个地址，否则则会返回一个空指针
            P1->show();//此处返回了一个P2的地址
        };
    }
    catch(bad_cast& a)
    {
        cout << a.what() << endl;
    }

    //typeid能够确定两个对象是否未相同类型
    //参数：1-类名，2-结果为对象的表达式
    //基本上所有编译器都包含着一个name()得类方法，返回一个随实现而异得字符串，通常为类的名称

    //重载了!=和==用于比较类型
    try
    {
        P1=NULL;
        typeid(test_2)==typeid(*P1);//是类型对比
        //若相同则会返回一个ture，否则返回一个false
        //若P1是一个空指针，则会返回一个bad_typeid的异常
        //注意如果要配合着dynamic_cast一起使用的话一定要使用类继承
    }
    catch(bad_typeid& e)
    {
        P1 = new base;
		cout << typeid(*P1).name() << endl;
        //若为空指针则会导致空间无法读取而报错
        //且typeid得类方法不能通过类指针进行调用
        std::cerr << e.what() << '\n';
    }
    
    //类型运算符
    //一共有四个1-dynamic_cast，2-const_cast，3-static_cast，4-reinterpret_cast
    //dynamic_cast是在类的层次上进行向上转换
    //const_cast用于指向中有一种用途的类型转换即const或volatile
    //volatile关键字是在读取数据时访问其所在的特殊地址进行读取而不是读取寄存器里的可能会被修改的数据，确保了数据的稳定访问。同时若数据没有改变则会自动把上次数据进行读取
    
    test_1 YSF;
    const test_1* Point=&YSF;

    test_1 * Tm=const_cast<test_1*>(Point);//此时会将Point的const关键字删除
    //const base * P3=const_cast<const base *>(Point);
    //同时只能向上转换不能向下转换//即以上语句错误
    //但是即使删去const，对于带有const关键字的变量来说仍是无法改变的

    //static_cast的类转换只能在基类和派生类之间进行

    //reinterpret_cast用于类型转换，不允许删除const
    struct TEst
    {
        int AA;
    };
    long SAS=1000;
    TEst* P4=reinterpret_cast<TEst*>(&SAS);//例如此
    cout << P4->AA << endl;
	return 0;
}
