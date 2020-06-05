#include<iostream>
using namespace std;
namespace test
{
    int A;
    string name;
    struct ss
    {
        int C;
        double B;
    } B;
    namespace test_1 //名称空间的嵌套性
    {
        namespace test_2
        {
            string name;
        }
    }
}
//空间别名
namespace tes=test;//使tes可以代表test空间
namespace //未命名名称空间
{
    int A;
}//该命名空间的名称的前缀作用域未：从声明点待该声明区结尾//不可用using进行调用
//其中变量和全局变量相似，但是不能在其他文件使用

//using声明和using编译命令
//using对特定标识符可用
//using编译命令对整个名称空间可用
void na();
int main(void)
{
    using namespace test;//使命名空间中所有名称都可用，进而不需要解析操作
    //虽然已经将名称空间视为在函数之外的声明，但是并没有使该文件中的其他函数使用这些名称
    //除非使用分析运算符

	using test::B;//使用后可以替代多次使用test::B
    int A=31;//这样不会发生冲突
    test::A=2;
    //若使用using test::A;则会报错

    B.B=2.3, B.C=1;
    cout << B.B << " " << B.C << endl;
	//编译器不会允许两个using两个名称空间中的两个相同的变量
    //若在代码块中出现和名称空间中名称一样的变量
    //则在使用时会被认定未代码块中的而不是命名空间中的
    //若要调用名称空间中的则需要使用分析运算符

    using namespace test::test_1::test_2;//调用名称空间
    test::test_1::test_2::name="Yinlianlei";
    //也可以在命名空间中使用using编译指令和using声明
    cout << test::test_1::test_2::name << endl;
	return 0;
}

void na()
{
    //ss A;//不可，在此处并未声明
    using test::ss;
    ss A;//可以使用
    A.B=3;
    cout << A.B << endl;
}

//名称空间及其前途即指导原则
//1-使用已命名的空间中的变量，而不是使用外部全局变量
//2-在已命名的名称空间中声明的变量
//3-若开发了一个函数库或类库，可以放在命名空间中
//4-仅将using作为将旧代码转化为新代码的权宜之计
//5-不要在头文件中使用using编译指令
//6-输入名称时，首选使用作用域解析运算符或者using声明的办法
//7-对于using声明，首选将其作用域设置为局部而不是全局

