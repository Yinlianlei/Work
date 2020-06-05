#include<iostream>
#include<valarray>//调用valarray类
using namespace std;
class test
{
private:
	valarray<int>qs;
public:
	test(int A) :qs(A) {};
	//对于类成员的初始化顺序按照定义顺序，若一个成员时成员类的初始化表达式的一部分时就会很重要
	//初始化类成员时使用的是成员名而不是类目
};
int main(void)
{
	//通常情况下，包含(类成员)(组合或者层次化)，私有继承，保护继承可用于实现has-a关系
	int GPS[5] = { 1, 2, 3, 4, 5 };
	valarray<int>test;//int变量
	valarray<int>test_1(4);//有四个元素的int数组(指定长度的数组)
	valarray<int>test_2(GPS, 4);//取GPS数组的前4个组成一个有四个元素的数组//常规数组中的值进行初始化的数组
	valarray<int>test_3(1, 3);//由三个元素，每一个都设置为一//所有元素都被初始化为指定值的数组
	valarray<int>test_4 = {101, 2, 3, 4 };//初始化列表
	//类方法
	cout << test_4.size()<< " ";//返回包含的元素数
	cout << test_4.sum()<< " ";//返回包含的元素总和
	cout << test_4.max()<< " ";//返回包含的最大值
	cout << test_4.min()<< endl;//返回包含的最小值
	cout << test_4[0] << endl;//和普通数组的调用方式一样
	//公有继承时，类可以继承接口，获得的接口是is-a关系的组成部分。而通过组合，类可以获得实现，但不能获取接口。
	//类中能用成员类的共有接口对成员进行操作，但是在外面无法这么做//类只获取了成员类对象的实现，但是没有继承接口
	//不继承接口是has-a的组成部分

	//C++中对于语句的约束，如explicit防止隐式转换和const限制数据修改
	//在编译阶段出现错误由于在运行阶段出现错误

	//由于成员类无法调用接口->无法重载运算符->可以通过辅助函数达成重载运算符的作用

	return 0;
}
