#include<iostream>
#include<array>
#include<valarray>
#include<vector>
#include<initializer_list>//提供initializer_list//包含begin()和end()
using namespace std;
void show(int& A) {cout << A << " ";};
void show1(const initializer_list<int>& A)
{
	for (auto* p = A.begin(); p != A.end(); p++)
	{
		cout << *p << " ";
	}
	cout << endl;
};
int main(void)
{
	//其他库//例如complex为复数提供类模板
	//vector，valarray，array

	//vector模板类式一个容器类和算法系统的一部分，支持面对容器的操作//相对于
	//valarray式面向数值计算的，不是STL的一个部分，对于数学运算提供一个简单直接的接口
	//array式提缓内置数组设计的，提供更好，更安全的接口，让数组更紧凑，效率更高效不支持push_back()和insert()，但是支持多个STL方法begin()之类的

	int A[10]{ 111,22,3,43,5,46,79,8,339,0 };
	valarray<int>tmp1(A,10);//valarray接口更简单但是性能在大多数情况下也是比较简单(效率不高)

	sort(&tmp1[0], &tmp1[9]);//由于接口简单所以连begin和end都没有//一般情况下不会出现问题
	//C++11标准添加了模板函数begin()和end()函数用于确定起点位置和终点位置
	sort(begin(tmp1), end(tmp1));
	for_each(begin(tmp1), end(tmp1), show);
	cout << endl;

	//求对数的方式log()和apply(log)//注：apply是一个对象的方法，用于返回一个对象
	
	array<int, 10>tmp2;//这个可以理解为数组，用输入方式进行初始化

	valarray<bool>tmp3 = tmp1 > 200;//此为创建一个储存tmp2元素是否大于200的值的真值

	//下标指定版本，例如slice，初始化为三个整数值：起始索引，索引数，跨距
	//起始索引：第一个被选中的元素的索引
	//索引数：指出要选择多少个元素
	//跨距：表示元素之间的间隔

	//例如slice(1,3,2)={1,3,5};
	tmp1[slice(1, 3, 2)] = 10;
	for_each(begin(tmp1), end(tmp1), show);
	cout << endl;

	//模板initializer_list(C++11新增)
	//容器初始化使用列表中的值进行初始化可以使用此模板作为参数进行初始化
	vector<int>tmp4 = { 1,2,3 };
	//==
	vector<int>tmp5({ 11,1,2,3 });//疑惑，为何会报错
	
	//C++11中的新初始化方法
	shared_ptr<int> tmp6{ new int [3]};

	vector<int>tmp7{ 10 };//==vector<int>tmp7({10});
	//初始化不能窄化转换，只能宽化转换

	show1({4,2,14,22});//使用initializer_list的函数
	//initializer_list为const关键词类型，所以不能修改//其旨在将一系列值传递给构造函数

	return 0;
}


