#include<iostream>
#include".h\Chapter_12.h"
using namespace std;
using namespace U_4;
int main(void)
{
	//访问控制
    //派生类可以访问基类的保护成员，但不能直接访问基类的私有成员
    //对于外部世界，保护成员和私有成员一样，对于派生类，保护成员和公有成员一样

    //使用protected会绕过基类中设计的数据保护措施//最好对数据成员采用私有访问控制，同时用类方法访问私有数据

    //抽象基类
    //ABC编程方法，抽出共有有成员组成基类，然后进行派生
    //纯虚函数：规范继承这个类的程序员必须实现这个函数
    test_2 T1("Yinlianlei","secret",4);
    test_3 T2=test_3(3.4,3.4,"yinlianlei",4);
    //T1.show();
    //T2.show();
    //T1.display();
    T2.display();
	
	return 0;
}
