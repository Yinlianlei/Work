#include<iostream>
using namespace std;
class test
{
private://类作用域，在类里是已知的，在类外面是未知的，而且是必须用::解析运算符才能进行
	int A;
	enum{BB=3};//初始化的一种方法
	static const int C = 4;//可以设置常量//若无static则无储存空间
public:
	test(int B) :
		A(B)
	{
	};
	void show();
};
enum class ts { S, M, L };//枚举申明，可以避免出现因为重名而导致的编译失败
enum class : long we { S，M，L };//也可以使用struct代替class//将底层类型定义为long类型，默认为int
void test::show()
{
	cout << "Complete." << endl;
};
int main(void)
{
	//对象数组
	test BB[2]//对象数组的初始化方法，必须有构造函数//也可直接使用默认构造函数
	{
		test(1),
		test(2)
	};
	BB[0].show();//使用和使用普通数组一样
	BB[1].show();
	ts D = ts::L;//赋值后可用于判断
	int C = int(ts::L);//可以进行强制转换
	cout << C;
	return 0;
}