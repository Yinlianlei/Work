#include<iostream>
#include<array>
#include<vector>
#include<set>//提供关联容器set和multiset
#include<map>//提供关联容器map和multimap
#include<iterator>
#include<algorithm>
using namespace std;
int main(void)
{
	//关联容器//容器概念的另一种改进
	//关联容器将键和值关联在一起
	//一般value_type指出了储存在容器中的值的类型，对于关联容器，key_type指出了键的类型

	//关联容器优点：提供了对元素的快速访问，允许插入新元素，但是不允许指定插入位置
	//关联容器通常是某种数实现(树是一种数据结构，其节点链接一个到两个节点)，树的查询速度更快

	//STL提供四种关联容器set,multiset,map,multimap.
	//set值类型和键相同，键是唯一的且不会有多个相同的键
	//multiset类似于set但是可以有多个值和键相同
	//map，值和键的类型不同，键是唯一的，每个键只对应一个值
	//multimap类似于map但是一个键可以和多个值关联

	int tmp[10]{ 0,1,2,3,4,5,6,7,8,9 };
	int tmpa[3]{ 110,23 };
	//1-set
	set<int>tmp1(tmp,tmp+10);//第二个模板参数是只是用来对键进行排序的比较函数或对象
	set<int>tmp2(tmpa,tmpa+2);//关联容器会自动排序
	//set存在一个将迭代器区间用作参数的构造函数(提供了将结合初始化的为数组内容的简单方法)
	//STL提供了通用函数用于操作set等对象
	set_union(tmp1.begin(),tmp1.end(),tmp2.begin(),tmp2.end(),ostream_iterator<int,char>(cout," "));
	//参数含义：前四个分别表示两个所需区间，最后一个是输出迭代器
	cout << endl;

	set<int>tmp3;
	set_union(tmp1.begin(), tmp1.end(), tmp2.begin(), tmp2.end(), 
		insert_iterator<set<int>>(tmp3, tmp3.begin()));
	//是tmp1和tmp2的合集交予tmp3
	copy(tmp3.begin(), tmp3.end(), ostream_iterator<int, char>(cout, " "));
	cout << endl;

	//set_intersection()查找交集
	//set_different()获得两个集合的差
	//接口于set_union相同

	//set()方法lower_bound()和upper_bound()
	//lower_bound()将键作为一个参数返回一个迭代器，该迭代器指向集合中第一个不小于键参数的成员
	//upper_bound()与上相似，返回的迭代器指向集合中第一个大于键参数的成员

	//2-multimap
	//multimap是可翻转的，经过排序的关联容器(与set类似)，但是键和值的类型不同，且一个键可以和多个值相关链

	multimap<int, string>tmp4;//创建一个键的类型是int，但是储存的值的类型是string
	//第三个模板参数指出用于对键进行排序的额比较函数或是对象，默认使用less<>

	//STL使用pair<class T, class U>将两个值(键类型和值类型)储存到一个对象中
	pair<int, string>name(1, "Yinlianlei");
	cout << name.first << " " << name.second << endl;
	pair<int, string>name1(2, "Yinlian");
	pair<int, string>name2(3, "Yin");
	//pair对象可以使用first和second来访问pair对象的两个部分

	//对于multimap对象的信息则可以用count接受键作为参数后输出，并返回具有该键的元素数目

	//lower_bound()和upper_bound()的处理和set时一致
	//equal_range()用键做参数，且返回两个迭代器，分别表示区间和间的匹配

	tmp4.insert(name);
	tmp4.insert(name1);
	tmp4.insert(name2);
	cout << tmp4.count(1) << endl;//返回键为1的元素数目
	multimap<int, string>::iterator it;//此处为multimap的迭代器用于控制循环等
	for (it = tmp4.begin(); it != tmp4.end(); it++)
	{
		cout << (*it).first << " " << (*it).second << endl;
	}

	//无序关联容器
	//和关联容器一样将值和键关联起来，并使用键来查找值
	//底层区别在于关联容器是基于书的结构的
	//而无需关联容器时基于数据结构哈希表的，旨在提高添加和删除元素的速度以及提高查找算法的效率
	//有四种，unordered_set，unordered_multiset，unordered_map，unordered_multimap



	return 0;
}
