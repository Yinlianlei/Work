#include <iostream>
#include ".h\Chapter_13.h"
using namespace std;
using namespace U_2;
int main(void)
{
    //多重继承带来的两个问题
    //1-不同基类继承同名的办法
    //2-从两个或更多相关基类哪里继承同一个类的多个实例

    Peoson A;
    test_1 B;
    test_2 C;
    base *point = &B;
    point->show();
    point = &C;
    point->show();
    //point=&A; //出现了二义性，不清楚是base派生类test_1还是teat_2
    point = (test_1 *)&A; //用于强制转换指定所含的基类
    point->show();
    point=(test_2*)&A;
    point->show();
    //虚基类派生出来的类只继承一个基类对象，解决了派生出现二义性的问题
    //此处的Peoson类的基类test_1和test_2类共用base类对象

    return 0;
}
