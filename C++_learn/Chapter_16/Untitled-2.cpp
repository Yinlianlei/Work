#include<iostream>
#include<iomanip>//提供控制字符
using namespace std;
int main(void)
{
	//ios_base描述了格式状态信息
    //ios_base是ios的基类

    //修改显示的计数系统
    //dec(十进制)，hex(十六进制)，oct(八进制)
    cout << 10 << endl;
    cout << hex;
    cout << 10 << endl;
    oct(cout);
    cout << 10 << endl;
    dec(cout);//==cout << dec ;

    //调整字段的宽度
    cout.width();//返回字段长度的当前设置
    cout.width(3);//设置成为指定长度

    //width只能影响到下一个项目，一次性使用
    cout << 3 << "#" << 3 << endl;
    cout << cout.width() << endl;
    //使用完后自动还原为默认值
	//默认右对齐，默认字段宽度为0，空格被设置为填充字符
    //C++只会增长字段不会阶段字段
    cout.fill('#');//修改填充字符
    cout.width(4);
    cout << 3 << "#" << 3 << endl;

    //设置浮点数的显示精度
    //取决于输出模式，默认情况下显示总位数
    cout.precision(2);//默认6位，percision()能够选择内部的精度
    //此处设置为2
    cout << 1.9+0.66 << endl;//末尾采取四舍五入（五舍去）

    //打印末尾的0和小数点
    cout.setf(ios_base::showpoint);
    cout.precision(4);
    cout << 3.4 << endl;
    //用于储存格式标记fmtflags，是bitmask类的typedef名
    //格式常量
    //ios_base::boolalpha   输入输出bool值，可以为true或false
    //ios_base::showbase    对于输出使用C++技术前缀(0,0x)
    //ios_base::showpoint   显示末尾的小数点
    //ios_base::uppercase   对于16进制输出卖室友大写字母，E表示法
    //ios_base::showpos     在正数前面加上+
    //注意：bitmask类型是一种用来储存各个位值的类型，可为整型，枚举，也可为STLbitset容器

    //setf有两种函数类型1-fmtflags setf(fmtflags);2-fmtflags setf(fmtflags, fmtflags);
    //第一种用于设置，第二种用于还原
    //第一个参数用于设置fmtflags值，第二个参数用于指出要清除第一个参数中的哪些位
    //fmtflags参数
    //ios_base::basefield   ios_base::dec   使用基数10
    //                      ios_base::oct   使用基数8
    //                      ios_base::hex   使用基数16
    //ios_base::floatfield  ios_base::fixed 使用定点计数法
    //                      ios_base::scientific    使用科学计数法
    //ios_base::adjustfield ios_base::left  使用左对齐
    //                      ios_base::right 使用右对齐
    //                      ios_base::internal      符号或技术前缀左对齐，值右对齐
    //例如
    cout.setf(ios_base::dec,ios_base::hex);//修改十进制显示为十六进制
    //定点计数法：精确度指的是小数位数而不是总位数
    //科学计数法：显示末尾的0

    //设置了一个fmtflags类，用于恢复默认设置
    ios_base::fmtflags RT = cout.setf(ios_base::showpoint);
    cout.precision(4);
    cout << 3.4 << endl;
    cout.precision(6);
    cout.setf(RT,ios_base::showpoint);
    cout << 3.4 << endl;
    //unsetf()可以将位恢复为0位；
    cout.unsetf(ios_base::showpoint);
    cout.unsetf(ios_base::hex);
    //cout.setf(0,ios_base::floatfield);//设置为默认模式//其中一种启动方式
    //提示，若已经是定点计数法，则setf(ios_base::floatfixed)则会切换至默认模式
    //标准控制符
    cout << showpoint ;//就可以直接调用setf(ios_base::showpoint);
    //目前是除了precision()不能通过cout直接调用外，以上提及的都可以

    //<iomanip>控制字符头文件
    cout << setprecision(3) << 3.2 <<endl
        << setfill('@') << setw(10) << 3.2 << endl;
    //setprecision()==cout.precision();
    //setfill()==cout.fill();//接受char字符
    //setw()==cout.width();
	return 0;
}
