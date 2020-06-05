#include<iostream>
#include<exception>
#include"Chapter_14.h"
using namespace std;
using namespace U_4;
int main(void)
{
	//栈解退
    //若无异常发生，则会在调用其余函数得函数顺序下依次返回，若为类对象，则会调用析构函数
    //如果出现异常终止，则会释放调用的函数的栈直到返回catch块代码，之后将会调用异常处理模块，而不是继续执行余下的diamagnetic
	
    //若在异常引发的情况下将下一个捕获这种异常的try-catch块组合进行处理
    //若未发现异常处理程序，默认情况下将会使异常终止

    int A;
    cout << "INPUT:" << endl;
    cin >> A;
    try
    {
        T_F(A);
    }
    catch(int B)
    {
        cout << B << endl;
    }
    catch(const char*S)
    {
        cout << S << endl;
    }
    //函数返回语句将控制权返回到调用函数的地址
    //throw语句则是将控制权向上返回到第一个包含能够不会相应异常的try-catch组合
    //引用的另一个特征：基类引用可以执行派生类对象
    //因而若是优先catch()基类，则会捕获异常基类和派生类。若相反则会一一对应
    //若不清楚异常类型，则可以使用...来代替所有异常并且捕获所有异常

    //exception类
    //代码可以引发exception异常，也可以将exception类用作基类
    //有一个名为what()的虚拟成员函数，可以返回一个字符串，该字符串的特征随着实现而异。
    //由于使虚方法，所以可以在派生类中重新自定义what类方法

    try
    {
        {
            Test TMP;
        }
    }
    catch(std::exception* e)
    {
        std::cerr << e->what() << "QwQ" <<endl;
    }
    //需要使用异常则可以在函数后面加上throw()加上异常，若发生则会进行判断//throw()表示不会引发异常

    //stdexcept类
    //定义了logic_error类和runtime_error类
    //logic_error是逻辑错误，编程方式可以避免
    //runtime_error描述的是可能在运行期间但难以与几何防范的错误
    //一般logic_error异常可以修复但是runtime_error不能修复

    //invlid_argument指出给函数传递一个意料外的值。
    //length_error指出没有足够的空间来执行所需的操作
    //out_of_bounds通常用于只是索引错误

    //bad_alloc让new引发异常

    //意外异常
    //未被捕获的异常。为被捕获的异常不会导致程序立刻异常停止。//程序会调用函数terminate()
    //可调用set_terminate()函数对terminate()进行设置

    //若发生意外异常，则会调用unexpected()函数对于terminate()进行修改
    //unexpected_handler()函数可以调用terminate(),abort(),exit()等来进行程序终止
    

    //注意事项：
    //对于类，由于栈解退的存在使得析构函数存在使得内存得以释放，但是对于动态分配的变量则会导致空间泄漏
    //则可以在catch()函数内加上delete即可避免
    






	return 0;
}
