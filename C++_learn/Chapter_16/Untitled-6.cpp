#include<iostream>
#include<fstream>
using namespace std;
int main(void)
{
	//随机存取
    //直接移动到文件的任何位置//一般由于数据库文件
    //该文件指出数据在主数据文件中的位置，然后程序便跳到这个位置，读取其中的数据
	fstream F;
    F.open("test.dat",ios_base::in|ios_base::out|ios_base::binary);
    //putback(),返回指定位置
    //可以实现文件的读写，同时继承了seekg()和seekp()方法
    //seekg()的作用是将输入指针移动到指定的文件位置
    //seekp()的作用是将输出指针移到指定的文件位置
    //fstream类指是使用缓冲区的来储存数据，因而指针指向的是缓冲区而不是文件

    //seekg
    //参数列表(streamoff, ios_base::seekdir)
    //参数列表(streampos)
    //streamoff值被用来度量相对于文件特定位置的偏移量
    //seekdir是由三个可能值
    //ios_base::beg      文件开始处的偏移量
    //ios_base::cur      文件当前位置的偏移量
    //ios_base::end      文件尾的偏移量
    F.seekg(0);//==F.seekg(0,ios_base::beg);
    F.seekp(0);//==F.seekp(0,ios_base::beg);
    //streampos的值指向文件中的一个位置//表示的是绝对位置，为相对于文件开始处的位置

    //检测文件指针的当前位置，对于输入流可以使用tellg()方法，输出流则是用tellp()
    //两者返回一个streampos值，对于fstream对象，两个指针是同一位置移动的

    //cstdio中有tmpnam()函数可以生成临时文件名，公有TMP_NAM个不同的文件名，其中每个字符不超过L_tmpnam个
	return 0;
}
