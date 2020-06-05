#include<iostream>
#include"Chapter_14.h"
#include<cstdlib>
using namespace std;
using namespace U_3;
int main(void)
{
	int A,B,Z;
    cout << "Please Input:";
    cin >> A >> B ;
    if(Judge(A,B,Z))//此方法相比起abort()而言速度更快
    {
        cout << "ERROR"<< endl;
        exit(1);
    }
    cout << A << B << endl;
    cin >> A >> B;
    try//必须卸载try块内才能引发异常，并处理
    {
        Judge1(A,B);//若出现异常，throw会导致函数调用序列后退知道找到try块
    }
    catch(const char *e)//表示处理程序与字符串异常匹配
    {
        cout << e << endl;
        cout << "ERROR1" << endl;
    }
    catch(int A)//与throw 返回的类型有关//例如类
    {
        cout << "What happened?" << endl;
    };
    


	return 0;
}
