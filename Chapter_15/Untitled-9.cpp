#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
int main(void)
{
	//算法
	//算法函数设计，有两个通用部分：1-用模板提供泛型，2-使用迭代器来提供访问容器中数据的通用表示

	//算法组
	//算法库分为四组
	//1-非修改式序列操作(以下三个在头文件algoritghm)
	//	对区间中的每个元素进行操作，不修改容器内容，例：find(),for_each()
	//2-修改式序列操作
	//	对区间中的每个元素进行操作，但是修改容器内容，例：transform(),random_shuffle(),copy()
	//3-排序和相关操作
	//	包括多个排序函数和奇特各类函数，包括集合操作
	//4-通用数字运算(单独在头文件numeric)
	//	将区间内容积累，计算两个容器的内部乘积，计算小计，计算相邻对象差的函数

	//算法的通用特征
	//使用迭代器和迭代器区间，

	//算法分类：就地算法(例：sort())，复制算法(例：copy())
	//有些算法有两个版本，分别为两种不同的算法

	//STL的string类
	//例如：next_permutation()将区间内容转换为下一种排列方式，成功返回true
	//以下代码可以打印出所有的字母排序
	string tmp;
	while (cin >> tmp && tmp!="quit")
	{
		cout << tmp << endl;
		while (next_permutation(tmp.begin(),tmp.end()))
		{//会自动提供唯一的排列组合
			cout << tmp << endl;
		}
	}

	vector<int>tmp2{ 1,2,3,4,5 };
	remove(tmp2.begin(), tmp2.end(),3);
	//此为一STL算法，用于删除指定大小的vector元素
	//链表的erase()用于删除区间
	for (int A : tmp2)
		cout << A << endl;
	//同时remove()返回一个超尾的迭代器地址

	//count()STL函数，获取区间内指定值出现的次数







	return 0;
}

