#include<iostream>
using namespace std;
class test
{
    public:
        enum mode {lenght=3};
    private:
        struct no
        {
            int A;
            struct no * next;//指向下一个地址
        };
        int AA=0;//在C++11种允许使用初始化
        no *Beganning;
        no *Ending;
        const int Len=0;
    public:
        test()
        {
            Beganning=Ending=NULL;
        }
        //test(int C):Len(C)
        //{
        //    Beganning=Ending=NULL;
        //};
        test(int D):Beganning(NULL),Ending(NULL),Len(D)//初始化列表
        {//实验此方法给私有成员赋值//对于const类成员必须使用此种方法
        };
        //这种格式只适用于构造函数
        //必须实验这种方式初始化构造函数成员(C++11前)
        //必须用这种方式初始化引用数据成员

        //链表处理方式
        //地址1->地址2->地址3->NULL
        //其中地址种保存着储存下一个地址的指针，而指向尾的链表的指针已经改变指向位置

};
int main(void)
{
	//链表
    //每个节点只包含一个指向其他节点的指针
    //通常最后一个节点的指针被设置成为NULL

    //在类声明中，结构类，枚举被称为嵌套进类中，作用域为整个类


	
	return 0;
}
