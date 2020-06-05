#include<iostream>
#include<memory>
#include<array>
#include<valarray>
#include<vector>
#include<ctime>
#include"Chapter_15.h"
using namespace std;
using namespace U_4;
void deemo(int& S);
bool TUN(int &A, int& B);
int main(void)
{
	srand((unsigned int)time(NULL)*2);
	//STL模板   //泛型编程
	//提供一组表示容器，迭代器，函数对象和算法的模板
	//容器是一个与数组类似的单元，可以储存若干个值
	//算法是完成特定任务(如对数组进行排序或在链表中查找)
	//迭代器是完成遍历的对象，广义指针
	//函数对象是类似于函数的对象，可以是类对象或函数指针(包括函数名)

	//1-vector模板类
	//vector矢量//操作与array模板类与valarray类似
	array<int, 2> tmp1 = { 1,2 };
	valarray<int>tmp2 = { 2,3 };
	vector<int> tmp3 = { 3,4 };

	for (int A = 0; A < 2; A++)
	{
		cout << tmp1[A] << endl
			<< tmp2[A] << endl
			<< tmp3[A] << endl;
	}

	//分配器：各种STL模板都接受一个可选的模板参数，改参数指定那个分配器对象来管理内存

	//使用vector模板只是方便动态分配数组

	//可对矢量执行的操作
	vector<int> tmp4 = { 5,6 };
	cout << tmp3.size() << endl;//返回容器中元素数
	tmp3.swap(tmp4);//交换两个容器的内容
	cout << tmp3[0] << " " << tmp3[1] << endl;
	//tmp3.begin();//返回指向容器中第一个元素的迭代器
	//tmp3.end();//返回一个超过文件尾的迭代器
	//[1,2,3,4,5]
	//begin()->[0] end()->[4] (begin(),end())->[0,4)
	tmp3.push_back(rand() % 20);//在末尾添加一个元素

	//迭代器，广义上是一个指针，也可以为解除引用的的操作
	//同时可以让STL能够为各种不同容器类提供统一的接口
	//迭代器的类型为iterator(为typedef定义)
	//例：对于vector可以如下操作
	vector<int>::iterator pd;
	pd = tmp3.begin();//end()超过结尾会导致使迭代到达结尾
	//也可以auto pd=tmp3.begin();
	*pd = 100;
	pd++;
	*pd = 200;
	cout << tmp3[0] << " " << tmp3[1] << " " << tmp3[2] << endl;
	
	//erase()方法删除矢量中给定区间的元素
	tmp3.erase(tmp3.end()-1, tmp3.end());//删除第三个元素，由于范围是[0,2)，end()指向[2]，所以删除范围为[2].
	//insert()则插入元素
	tmp3.insert(tmp3.end(),tmp3.begin(),tmp3.begin()+1);//在末尾插入一个元素，其为begin()到begin()+1所指向的元素
	pd = tmp3.begin();
	for (; pd != tmp3.end(); pd++)
		cout << *pd << " ";
	cout << endl;
	pd = tmp3.end() - 1;
	*pd = 50;
	//STL模板对于搜索，排序，随机排序等都死通过非成员函数进行的
	//代表性STL函数，for_each(), rand_shuffle(), sort()

	//for_each()可以隐式使用迭代器
	pd = tmp3.begin();
	for_each(tmp3.begin(), tmp3.end(), deemo);//最后一个是指向函数的指针
	cout << endl;
	//使从开始到结尾的所有元素都置于函数对象中进行操作

	//Random_shuffle()随机排列区间内的元素
	random_shuffle(tmp3.begin(), tmp3.end());//使tmp3的所有元素全部随机排列
	//random_shuffle()对于容器类有一定限制，这个类必须允许随机访问
	for_each(tmp3.begin(), tmp3.end(), deemo);
	cout << endl;

	//sort()也要求对于类的随机访问//其他方式排列也可以，比喻运算符重载
	sort(tmp3.begin(), tmp3.end());//使tmp3的所有元素进行排序//默认<运算符
	for_each(tmp3.begin(), tmp3.end(), deemo);
	cout << endl;
	sort(tmp3.begin(), tmp3.end(), TUN);//第二种格式，可以使用迭代器使元素可以按照函数内的方式进行
	for_each(tmp3.begin(), tmp3.end(), deemo);
	cout << endl;

	//基于范围的for循环
	int AA[9]{ 1,2,3,4,5,6,7,8,9 };
	for (int A : AA)//指明类型名称后，循环体用指定变量一次访问容量的每个元素
		cout << A << " ";//此处AA为地址，A取AA地址的值
	cout << endl;


	return 0;
}

void deemo(int& S)
{
	cout << S << " ";
}

bool TUN(int& A, int& B)//降序排列
{
	if (A > B)
		return true;
	else
	{
		return false;
	}
}



	return 0;
}
