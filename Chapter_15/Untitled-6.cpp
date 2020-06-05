#include<iostream>
#include<array>
#include<vector>
#include<list>
#include<iterator>
#include<queue>
#include<stack>
using namespace std;
int main(void)
{
	//容器种类
	//容器概念是具有名称的通用类型//容器类型是可用于创建具体容器对象的模板
	
	//容器概念
	//描述了所有容器的通用类型//容器概念指定了所有STL容器类都满珠的一系列要求

	//容器复杂度的所需时间：编译时间<固定时间<线性实践

	//添加要求来改进基本的容器概念//序列是一种重要的改进：能够在末尾和开头增删数据

	//序列概念使得迭代器至少是正向迭代器这样要求，可以保证元素将按照特定的顺序排列

	//七种序列容器类型
	//1-vector//数组类，提供了自动内存管理，可以动态的改变vector对象的长度
	//拥有反转容器概念(rbegin()和rend())//操作时间尾线性//强调通过随机访问进行快速访问
	int A[3]{ 1,2,3 };
	vector<int> tmp1(size(A));
	copy(A, A + 3, tmp1.begin());
	copy(tmp1.begin(), tmp1.end(), ostream_iterator<int, char>(cout, " "));
	cout << endl;

	//2-deque//双端队列，通常在SL中用于实现类似于vector容器，deque对象的开始位置插入和删除元素的实践是固定的
	
	//3-list//双向链表//在list头文件中添加
	//除了第一个和最后一个元素外，其他元素都与前后的元素相链接，插入和删除时间尾固定，list强调快速插入和删除
	//list也是可反转容器，但是 不支持数组表示法和随机访问//删除或插入链表迭代器指向的元素将不会改变
	
	//list成员函数
	//merge(list<T,Alloc>& x)	将链表x和链表合并
	//remove(const T & val)		从链表中删除val的所有实例
	//sort()					使用<运算符进行排序
	//splice(iterator pos,list<T,alloc>x)	将链表x的内容插入到pos的前面，x将为空
	//unique()					将连续的相同元素压为单个元素

	list<int> tmp2(10, 0);
	tmp2.insert(tmp2.end(), A, A + size(A));
	copy(tmp2.begin(), tmp2.end(), ostream_iterator<int, char>(cout, " "));
	cout << endl;

	//insert()将原始区间的副本插入到目标地址
	//splice()则将原始区间移到目标地址
	//unique()只能将相邻的值压缩为单个值
	//sort()为非成员函数，不能用于链表，随用于随机访问迭代器，但是方式使用随机访问功能

	//4-list工具箱：由list的方法构成

	//5-forwa_list
	//容器类，单链表，只能链接下一个节点

	//6-queue//在头文件queue中添加
	//模板类，且为适配器，战士典型的队列接口
	//不可以随机访问元素，遍历队列
	//可以添加元素到队尾，删除队首元素，查看队首和队尾的值，检测元素数目和测试队列是否为空

	//queue成员函数
	//1-empty()		如果队列为空，则返回true否则false
	//2-size()		返回队列的元素数目
	//3-front()		返回队列首元素的引用
	//4-back()		返回指向队尾元素的引用
	//5-push(const T&X)	在队尾插入X
	//6-pop()		删除队首元素
	//注意：如果要使用队列中的值，应先使用front()检索后用pop()从队列中删除

	//7-priority_queue
	//模板类，且为适配器，支持操作和queue相同
	//主要差别是最大元素被移到队首，内部区别在于默认底层类是vector
	priority_queue<int>tmp3;
	priority_queue<int>tmp3_2(greater<int>);
	//greater预定义函数对象

	//8-stack//在头文件stack中声明
	//适配器类，底层类默认vector，提供电信栈接口
	//不可以随机访问栈元素，遍历栈
	//可以进行栈的基础操作，将压入推到栈顶，从栈顶弹出元素，查看栈顶的值，检测元素数目和测试栈是否为空

	//stack成员函数
	//1-empty()		如果栈为空返回true
	//2-size()		返回栈中的元素数目
	//3-top()		返回栈顶的元素的引用
	//4-push(const T& X)	在栈顶插入X
	//5-pop()		删除栈顶元素
	//注意：如果要使用栈中的值，必须先使用top()检索，然后用top()从栈中剔除
	stack<int>tmp4;


	//9-array
	//模板类，非STL容器，长度固定//STL算法可用于array，例如copy(),for_each();





	return 0;
}


