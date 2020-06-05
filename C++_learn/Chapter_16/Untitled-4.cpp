#include<iostream>
#include<fstream>
using namespace std;
int main(void)
{
    //文件输出
	ofstream fout("test.txt");//==fout.open("test.txt");
    //在windous系统中"E:\\Program.c++\\Learn_C++\\"=="E:\Program.c++\Learn_C++"
    fout << "Yinlianlei" << endl;
    //由于ostream是ofstream类的基类，所以可以使用所有ostream的方法
    //默认模式是删除文件已有类容，重新输入

    //文件输入
    string name;
    ifstream fin("test.txt");
    fin >> name;//如同上面一样可以管理冲文件中输入的流//可以如同cin一样使用
    cout << name << endl;

    fin.close();
    fout.close();//文件输入或输出流达到尾时会自动关闭文件
    //仅是断开流与文件的关联
    //string类有一个c_str方法返回一个char类型的字符串参数

    //流状态检查
    cout << fin.is_open() << endl << fin.fail() << endl << !fin << endl;
	//is_open若成功打开将会返回0，若出现failbit,badbit,eofbit将会返回1
    //也可以使用fail()的返回值或!fin(会自动判定使用bool值)

    //常见格式,以下三种
    if(fin.fail())
    {
        cout << 233 << endl;
    }
    if(!fin.good())
    {
        cout << 233 << endl;
    }
    if(!fin)
    {
        cout << 233 << endl;
    }
	return 0;
}
