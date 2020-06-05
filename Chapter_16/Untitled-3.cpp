#include<iostream>
using namespace std;
int main(void)
{
	//使用cin进行输入
    //cout和cin有着描述六状态的数据成员
    //流状态由三个ios_base元素构成，eofbit，badbit和failbit，每个都是一位
    //cin操作到达文件末尾时，将设置eofbit，cin未能读取到于其的字符时，会设置failbit
    //在一些无法判断失败破坏流时会使用badbit
    //三个全为零说明一切顺利

    //流状态
    //eofbit        如果到达文件尾，则设置1
    //badbit        如果流被破坏，则设置1
    //failbit       如果输入操作未能读取于其的字符或输出操作没有没有写入预期的字符，则设置1
    //goodbit       另一种表示0的方法
    //eof()         如果eofbit被设置，则返回true
    //bad()         如果badbit被设置，则返回true
    //fail()        如果failbit被设置，则返回true
    //rdstate()     返回流状态
    //exceptions()  返回一个位掩码，指出哪些标记导致异常引发
    //exceptions(isostate ex)   设置哪些状态将导致clear()异常
    //clear()       将流状态设置为s;s默认值为0(goodbit())
    //setstate(iostate s)   调用clear(rdstate()|s)

    //设置状态
    //例如
    //cin.clear();
    //恢复默认状态，可以继续输入而不会因为错误类型的输入导致问题
    //cin.clear(cin.eofbit);
    //清除cin的eofbit的状态

    //处理异常
    //使用exceptions()来控制因此如何被处理
    //修改流后clear()会将流状态和exceptions()返回的值进行比较

    //处理输入异常的代码
    int A,B;
    while(!(cin >> A))
    {
        cin.clear();
        while(cin.get()!='\n')
            continue;
    }
    //另一个版本
    cin >> B;
    if(cin.fail()&& !cin.eof())//fail()在failbit或eofbit被设置时返回true
    {
        cin.clear();
        while(cin.get()!='\n')
            continue;
        cout << "FAILURE" << endl;
    }
    else
    {
        cout << "WHAT?" << endl;
        exit(1);
    }
    //其他istream类方法
    //1-单字符输入
    char ch;
    cin >> ch;
    while(ch!='$')
    {
        cout << ch;
        cin >> ch;
    }//会跳过空格//且由于抽取运算符跳过了换行符所以空格并不会停止程序
    //cin.get(ch)//只要是有效输入就可以返回true，且可以直接使用Ctrl+Z输入文件尾
    //成员函数get(void)//使用返回值基于程序
    //例如
    while((ch=cin.get())!=EOF)
    {
        cout << ch;   
    }
    //此处使用cin.get()的返回值，到达文件尾后将会返回EOF
    //cin.get(ch)于ch=cin.get()的区别之一
    //输入时的函数返回值，前者指向istream的引用，后者为字符编码
    //同时使用>>,cin.get(char&)无法读取空格，而使用返回值可以读取空格

    //2-字符串输入
    //istream & get(char*,int,char);
    //istream & get(char*,int);
    //istream & getline(char*,int,char);
    //istream & getline(char*,int);
    //第一个参数为访问的内存单元地址，第二个单位是读取长度，第三个参数是分界字符
    //get()读取分界字符却不会丢弃，getline()会丢弃
    //读取到分界字符时读取将会停止

    //ignore()成员函数，接受两个参数
    //一个是数字指定最大字符数，一个时字符，做分界字符
    //istream & ignore(int =1,int =EOF)//EOF导致ignore()读取指定的字符或读取到文件尾
    //ignore可以用来清空某个数组的数据，格式A为一char数组，cin.ignore(A,'\n');

    char AA[20];
	cin.clear();
	cin.getline(AA, 20, 'l');
	cin.ignore(20, 'i');
    //忽略掉分界字符及分界字符之前的所有字符，并把后面的流保留在缓冲区
	cin.getline(AA, 20);
    //然后读取了缓冲区里的数据，且此数据已经被ignore处理
	cout << AA << endl;
    
    //其他istream方法
    char * CH=new char [10];
    cin.read(CH,10);//read会读取20个字符并保存再CH里且不会加上\0字符
    //通常与write一起使用
    cout.write(CH,10)<< endl;
    //putback()将一个字符插入到输入字符串中，被插入的字符将会是下一个输入字符的第一个字符
    //peek()函数返回输入中的下一个字符，但不抽取流中的字符
    //gcount()返回上一个非格式化抽取方法读取的字符数
    cin >> CH;
    int mun=cin.gcount();//读取上一个出入的字符数
    cin.putback('#');
    char ch1=cin.peek();//此处返回了被截留在流中的\n
    cout << CH << endl <<ch1 << endl << mun << endl;
    


	return 0;
}
