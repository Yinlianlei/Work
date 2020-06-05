#include<iostream>
#include".h\Chapter_13.h"
using namespace std;
using namespace U_1;
int main(void)
{
	//保护继承
    //基类的公用函数和保护函数会成为派生类的保护函数
    //基类接口可以通过保护继承一直在派生类中存在
    //而私有继承会在第二个派生类上变成无法访问的私有类

    //使用using重新定义访问权限
    //让基类的方法在派生类外可用
    //方法1-定义一个使用改基类方法的派生类方法
    //例：
    //int test::sum()
    //{
    //  return valarry<int>.sum();    
    //}//应用于valarry类
    //方法2-可以把函数调用包装在另一个函数调用中//使用using声明指明派生类可以使用特定的基类成员
    //声明时可以在公有成员或者私有成员
    //只能声明成员名，没有圆括号，函数特征标，返回类型
    //可以是非const和const都可用
    //只适用于继承，不适用于包含
    Yin A;
    A.show();//可行
    A.show1();






	
	return 0;
}
