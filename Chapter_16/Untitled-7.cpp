#include<iostream>
#include<fstream>
#include<sstream>//提供一个ostringsteram类，用于给string类分配更为宽广的空间
using namespace std;
int main(void)
{
	//内核格式化
    ostringstream Fstr;
    //同时由于其产生的是字符串流，事以内存中用户定义的字符数组为输入输出对象，称为内存流
    Fstr << "What is it?"  << endl
         << "I don't know."<< endl;
    //格式化文本进入缓冲区，该对象使用动态内存分配增大缓冲区

    //此类拥有一个str()方法用以返回一个被初始化为缓冲区内容的字符串对象
    //同时此方法可以起到使信息不能写入该对象
    string Cova;
    Cova=Fstr.str();
	cout << Cova;

    istringstream Fin(Cova);
    //此类允许使用istream方法获取istringstream对象中德数据
    //可使用string类进行初始化//可以使用istream中德方法读取其中的数据
    string word;
    while(Fin>>word)
    {
        cout << word << endl;
    }


	return 0;
}
