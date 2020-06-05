#include<iostream>
#include".h\Chapter_16.h"
using namespace std;
using namespace U_1;
int main(void)
{
	//文件的输入输出
	//流和缓冲区//输入和输出看作字节流
    //输入时程序冲输入流中抽取字节//输出时程序将字节插入到输出流中

    //程序对于输入的管理：
    //将流与输入去向的程序关联起来//将流与文件连接起来
    
    //可以使用缓冲区更高效的处理输入和输出
    //作为将数据从设备输入到程序或从程序输入到设备

    //streakbuf:提供管理输入输出缓冲区内存的类方法
    //ios_base:表示流的一般特征
    //ios:基于ios_base，柏寒一个指向streambuf类对象的指针
    //ostream:基于ios，k提供输出方法
    //istream:基于ios，提供输入方法
    //iostream:基于ostream和istream类

    //输入重定向<和输出重定向>
    //<可以计算输入的文件，>可以将结果输出到一个额外文件中

    //<<默认含义是按位左移运算符//ostream类对其镜像了重载，使其能够重载为输出，即插入运算符

    //指针的cout输出
    char * test="Yinlianlei";
    cout << test << endl;
    cout << *test << endl;//输出数组的首字母
    cout << &test << endl;//输出地址

    char AA='a';
    //其他ostream类输出
    cout.put(AA).put('s').put('s').put(66).put(67);//输出字符
    cout << endl;
    cout.write(test,4);//输出字符串,第二个参数是输出多少位//遇到空格会自动停止大一字符
    //只打印指定数目的字符，即使超过了字符串边界
    
    //刷新缓冲区
    //ostream类直到缓冲区满了才会将发送到目标地址，flush()可以强制提前刷新输出
    flush(cout);
    cout << "Test" << flush;//此处清空了缓冲区，里面的内容被发送了出去
    cout << "Test-1" << endl;

    //标准输出
    cerr << "Tets-1" << endl;//无缓冲直接输出到屏幕
    clog << "Test-2" << endl;//经过缓冲区，满后输出至屏幕
	return 0;
}
