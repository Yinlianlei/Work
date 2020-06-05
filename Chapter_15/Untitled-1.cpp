#include<iostream>
#include<string>
#include"Chapter_15.h"
using namespace std;
int main(void)
{
    //string类
    //string类有九种构造函数(C++11新增两种)
    //1-string(const char*s)            创建一个指向s的对象
    //2-string(size_type n, char c)     创建一个包含n个元素的string对象，每个元素初始化为c
    //3-string(const string& str)       将一个string对象初始化为str对象
    //4-string()                        创建一个长度为零的string对象
    //5-string(const char* s,size_type n)   将一个string对象初始化为字符串s的前n个字符，即使操过了字符串的结尾
    //6-templete<class Iter>            初始化为区间[begin,end)内的字符，
    //  string(Iter begin,Iter end)     其中begin和end为指针，字符不包括的end
    //7-string(const string & str,                          将一个string对象初始化为对象str中从位置pos开始到结尾的字符
    //  string size_type pos=0,size_type n=npos)            ，或冲位置pos开始的n个字符
    //8-string(string &&str)noexcept    将一个string对象初始化为string对象str，并可能修改str(移动构造函数)
    //9-string(initializer_list<char> il)   将一个string对象初始化为初始化列表il的字符

    string name("Yinlianlei");
    string name2("Yinlianlei",3,4);
    string name1("Yinlianlei",3);
    string name3("Yinlianlei",7,3);

    cout << name << endl 
        << name1 << endl
        << name2 << endl
        << name3 << endl;

    string name4;
    getline(cin,name4,':');
    cout << name4 << endl;
    
    //string版本的getline()函数从输入中读取字符，并将其存储到目标string中，直到发生
    //1-eofbit()到达文件尾，eof()返回true
    //2-遇到分界字符(默认'\n')
    //3-达到最大字符允许值

    name1="Yinlianlei";
    char A[]="Yinlianlei";
    if(name==name1)//string类的==运算符的使用
    {
        cout << "Yes." << endl;
    }
    if(A==name1)//char和string类的运算符的使用
    {
        cout << "YES" << endl;
    }
    //string类的length()和size()返回字符串中的字符数
    cout << name.size() << endl << name1.length() << endl << endl;
    //find()查找字符串或字符(一共四个版本)
    //size_type find(const string & str, size_type pos=0)   //从字符串pos处开始查找字符串str
    //size_type find(const char* s, size_type pos=0)    //从字符串pos处开始查找字符串s
    //size_type find(const char *s, size_type pos=0, size_type n)   //从字符串pos处开始，查找s的前n个字符组成的字符串
    //size_type find(char ch, size_type pos=0)const     //从字符串pos位置开始，查找字符ch
    //以上若找到则会返回字符/字符串首次出现的首字符索引，否则会返回string::npos
    //此外还有rfind(), find_first_of(), find_last_of(), find_first_not_of()等，重载也类似
    //rfind()查找子字符串或字符最后一次出现的位置
    //find_first_not_of()查找第一个不包含在参数中的字符

    //string类的其他功能：
    //capacity()返回当前分配给字符串的内存块大小，reserve()请求内存块的最小长度
    string tmp;
    cout << name.capacity() << endl
        << tmp.capacity() << endl;
    tmp.reserve(10);//分配了内存块
    cout << tmp.capacity() << endl;

    //字符串种类
    //basic_string模板有四个类具体化，char，wchar_t，char16_t，char32_t
	
	return 0;
}
