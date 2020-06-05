#include<iostream>
#include<fstream>
using namespace std;
int main(int argc,char *argv[])//命令行处理技术
//argc为命令行的参数个数，argv为一个char指针数组
//argv[0]为命令行中第一个字符串//一般为程序名，例.\a test.txt 则argc为2，argv={".\a","test.txt"}
{
    //打开多个文件
	ifstream Fin;
    Fin.open(argv[1]);
    if(!Fin.is_open())
    {
        cout << "ERROR" << endl;
        exit(1);
    }
    string name;
    Fin >> name;
    Fin.close();
    Fin.clear();//重置流的状态，对于程序无害//一般在调用第二个文件前会使用
    cout << name << endl;
    
    //文件模式，读，写，追加，在open类方法调用时设置
    //ios_base也定义了一个openmode类型用于标示模式，类型和fmtflags一样
    //常量与含义：
    //ios_base::in      打开文件并读取
    //ios_base::out     打开文件并写入
    //ios_base::ate     打开文件并移动到文件尾
    //ios_base::app     追加到文件尾
    //ios_base::trunc   如果文件存在则截短文件//清空文件并重新写入
    //ios_base::binary  二进制文件

    ofstream fout;
    fout.open(argv[1],ios_base::out|ios_base::trunc);
    //ifstream默认为ios_base::in, ofstream默认为ios_base::out|ios_base::trunc(打开文件并读取)
    //如果想要在打开文件后面加上内容则可以设置为
    //ios_base::out|ios_base::app //|为合并模式，可以两个同时设置
    //也可以使用C语言风格的字符形式
    fout << "YinSuo22" ;
    fout.close();
    fout.clear();

    //二进制文件
    //使用二进制文件的好处，不需要转换，便于程序读取，且可以大块的储存数据，一般情况下二进制文件占用数据更小
    //使用ios_base::binary可以做到
    //使用二进制文本模式，程序将数据从内存传输到文件中，将不会发生隐藏的转换
    //对于Windows系统，使用回车和换行标示换行符，Linux使用换行来表示
    //一般使用write进行转换，由于其不会进行任何转换
    fout.open("test.dat",ios_base::binary);
    string name1;
    cout << "Input your name:" << endl;
    cin >> name1;
    fout.write(name1.c_str(),name1.length());
    //若是实现文件的恢复功能，可以使用read和write进行读取存储在临时的流里进行临时备份，用以复原

    //其中write和read函数可以读取以相同格式储存的文件中的数据
    //不方便的地方，必须强制转换为char的指针且必须用&取其地址
	return 0;
}
