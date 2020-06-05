#include<iostream>
#include<memory>
#include<vector>
#include<array>
#include<iterator>//可以调用ostream_itretaor
using namespace std;
void show(int A)
{
	cout << A << " ";
}
int main(void)
{
	//泛型编程
	//面向对象编程关注的是变成数据方面，而泛型编程关注的是算法
	//泛型编程旨在编写独立于数据类型的代码(C++使用的工具是模板)

	//迭代器特征：
	//1-能够对迭代器执行解除引用的操作，一边能够访问它的引用值
	//2-应能够将一个迭代器赋予另一个
	//3-应能够将一个迭代器与宁一个进行比较
	//4-应能够使用迭代器遍历容器中的所有元素

	//例如迭代器类，重定义运算符可以达成一些迭代器特性

	//迭代器类型：
	//1-输入迭代器，2-输出迭代器，3-正向迭代器，4-双向迭代器，5-随机访问迭代器

	//输入迭代器
	//访问容器中的值，视来自容器中的值为输入，因而可以视输入迭代器用于读取容器的信息
	//要求必须访问所有的值(可以通过++运算符来实现)//只能前进不能倒退，就像链表一样

	//输出迭代器
	//将信息输入到容器的迭代器，只需要解除应用让程序能够修改容器值而不能读取

	//正向迭代器
	//与输出迭代器类似，只能使用++运算符来遍历容器，其总是按相同的顺序遍历一遍系列值
	//正向迭代器递增后，仍然可以对前面的迭代器值解除引用

	//双向迭代器
	//在正向迭代器的基础上加上递减运算符，且加上末尾和首个元素进行连接

	//随机访问迭代器
	//能够直接跳到容器的任意位置的任意元素，则叫做随机访问
	//在双向迭代器的特定基础上加上随机访问操作和用于对元素进行排列的关系运算符

	//迭代器的层次结构

	//STL使用概念属于来描述一系列的要求
	//使用改进来描述概念上的继承

	//1-将指针用作迭代器
	//迭代器是广义指针，迭代器是STL算法的接口
	int A[10]{ 11,22,34,13,46,24,37,65,8,11 };
	sort(&A[0], &A[10]);
	for (int B : A)
		cout << B << " ";
	cout << endl;

	vector<int>tmp1(10);
	copy(A, A + 10, tmp1.begin());
	//copy()STL算法可以使一个容器的内容转移到另外一个容器内
	for_each(tmp1.begin(), tmp1.end(), show);
	cout << endl;

	//以下为一个输出迭代器
	//ostream_iterator模板--适配器，一个类或函数，可以讲一下其他接口转换为STL使用的接口
	ostream_iterator<int, char> OUT(cout, ",");//使用输出流
	//第一个参数指出了被发送给输出流的数据类型，第二个参数指出了输出流使用的字符类型
	//构造函数第一个参数指出了使用的输出流，也可以用于文件流的操作，第二个参数指出了间隔符
	copy(tmp1.begin(), tmp1.end(), OUT);//将tmp1的数据copy到输出流中即可显示在屏幕上

	//以下是一个输入迭代器
	vector<int> tmp2(3);
	//istream_iterator<int, char> IN(cin);
	//第一个参数指出要读取的数据类型，第二个参数指出输入流使用的字符类型
	copy(istream_iterator<int, char>(cin),
		istream_iterator<int, char>(), tmp2.begin());
	//此处结束输入为输入错误的类型为止，否则会报错
	sort(tmp2.begin(), tmp2.end());
	for_each(tmp2.begin(), tmp2.end(), show);
	cout << endl;

	//其他有用的迭代器//专用的迭代器类型
	//reverse_iterator,back_iterator,front_insert_iterator,insert_iterator

	//1-reverse_iterator
	//执行递增操作将导致它被递减
	//vector的成员函数中rbegin()指向超尾的反向迭代器，rend()指向第一个元素的反向迭代器
	for_each(tmp1.rbegin(), tmp1.rend(), show);//此处反向输出
	cout << endl;
	vector<int>::reverse_iterator pr;
	for (pr = tmp1.rbegin(); pr != tmp1.rend(); pr++)
		cout << *pr << " ";
	cout << endl;

	//back_insert_iterator将元素插入到容器尾部(只允许在文件尾)
	//front_insert_iterator将元素插入到容器前端
	//insert_iterator构造函数的参数指定位置
	vector<int> tmp3(10);
	copy(tmp1.begin(), tmp1.end(), tmp3.begin());
	back_insert_iterator<vector<int>> qs(tmp1);//必须声明容器类型使迭代器使用合适的容器方法
	copy(tmp1.begin(), tmp1.end(), back_insert_iterator<vector<int>>(tmp3));
	for_each(tmp3.begin(), tmp3.end(), show);
	cout << endl;




	return 0;
}
