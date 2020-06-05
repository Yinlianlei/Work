#ifndef _Chapter_14_
#define _Chapter_14_
#include<iostream>
#include<exception>
#include<cstdlib>
using namespace std;
namespace U_1
{
    class Test
    {
        private:
            string name;
        public:
            friend class Test_1;//Test_1的所有方法都是Test类的友元类方法
            Test(){name="Yinlianlei";};
            Test(string A):name(A){};
            void show(){cout << name << endl;};
    };
    class Test_1
    {
        private:
            int Sum;
        public:
            Test_1(){Sum=0;};
            Test_1(int A):Sum(A){};
            void show(Test& Tmp){Tmp.show();cout  << Sum <<endl;} ;
            //若要调用原始类中的数据，必须在其中的类方法中的特征标上加上对于原始类的引用
            //可以调用私有和公有的函数
            //循环依赖，一个类调用另一个类的类方法且在调用的类前面声明，两者的方法调用相互依赖
            //避开循环依赖的方法，此处可以在Test类前加上class Test_1//且顺序不能反
            //例:class Test;
            //  class Test_1{};//只包含方法声明
            //  class Test{};
            //  //Test_1方法的定义

            //类方法也可以称为内敛方法，且声明与定义必须放在一个文件内
    };
    //类之间互相可以影响//互为友元类
    class Test_2
    {
        friend class Test_3;
        private:
            int A;
        public:
            Test_2(){A=0;};
            Test_2(int AA):A(AA){};
            void show();


    };
    class Test_3
    {
        friend class Test_2;
        private:
            string name;
        public:
            Test_3(){name="Yinlian";};
            Test_3(string A):name(A){};
            //对于Test_3使用的Test_2类的方法，可在Test_3声明前声明，但是必须在Test_3类后定义
            void show(Test_2& A){A.show();cout << name << endl;};
    };
    void Test_2::show()
    {
        cout << A << endl;
    }
    //共同的友元
    class Test_5;//必须声明在之前
    class Test_4
    {
        private:
            int Grade;
        public:
            Test_4(){Grade=0;};
            friend void show(Test_5&,Test_4&);
            friend void show(Test_4&,Test_5&);
    };
    class Test_5
    {
        private:
            string name;
        public:
            Test_5(){name="Yinlianlei";};
            friend void show(Test_5&,Test_4&);
            friend void show(Test_4&,Test_5&);
    };
    void show(Test_5 & A,Test_4 & B)//声明之后就可以访问两个类的私有和公有成员函数和成员数据
    {
        cout << A.name << ":" << B.Grade << endl;
    }
    void show(Test_4 & B,Test_5 & A)
    {
        cout << A.name << ":" << B.Grade << endl;
    }
};
namespace U_2
{
    //嵌套类
    //把类声明放在另一个类里
    //包含类的成员函数可以创建和使用成员类的对象，仅有声明与保护和公开时才可以被访问
    
    //嵌套类与包含不同
    //包含：将类对象当作一个类的成员
    //嵌套是定义一个类型，进行包含嵌套类的声明的类中有效，且不会当成类成员
    //一般用于帮助实现另一个类，避免名称冲突

    //结构是一个默认情况下公有的类，却无构造函数和类的功能
    class test_1
    {
        private:
            class INL
            {
                public:
                    int Grade;
                    string Name;
                    INL():Name("Yinlianlei"),Grade(0){};
            };
        public:
            void show()
            {
                INL *TMP=new test_1::INL();//用于快速初始化，且更为安全和简短
                //相比较于结构而言
                cout << TMP->Name << TMP->Grade << endl;
            }
    };

    //嵌套类和访问权限
    //镶嵌类的位置决定了镶嵌类的作用域
    //1-作用域，private，protected，public的作用于是一样的
    //2-访问控制，和上面的访问权限是一样的道理

    //模板中的嵌套，和平时使用模板类没有不同之处
};
namespace U_3
{
    //异常，用于处理程序出现无法运行或错误情况的一种解决工具
    //较新的编译器会又相应功能//例如N/0，可能会由cout表示为Inf，inf，INF等表示

    //C stdlib头文件中的abort()参数
    //实现是向标准错误流(cerr中使用的)发送消息(程序异常终止)，然后终止程序。
    //值随着实现而异//VS里直接显示是否终止，VSC+G++则会在停顿一小段事件后退出程序

    //返回错误码
    //相比异常终止更为灵活，使用的是函数的返回值进行指出(exit()有些类似)
    //一般是使用指针参数或引用参数将值返回给调用程序，并使用函数的返回值指出成功还是失败

    bool Judge(int A,int B,int & C)
    {
        if(A==-B)
        {
            //abort();//VS被中断，VSC卡顿一会后退出
            C=INT_MAX;
            return 1;
        }
        else
        {
            return 0;
        }
	};

    //异常机制
    //1-引发异常，2-使用处理程序捕获异常，3-使用try块
    //throw 语句 进行跳转指出异常的特征
    //异常处理程序对于异常进行捕获，一般位于要处理问题的程序中，使用catch关键字表示捕获异常
    //catch指出异常相应后，用花括号括起代码块并指出处理的措施，catch关键字与异常类型作为标签，指出出现异常时应对跳向那个代码块
    //try块标识符表示特定异常可能被激活的代码块，后面可能是一个或多个catch块，其花括号内表面应当注意的异常
    bool Judge1(int A,int B)
    {
        if(A==-B)
        {
            //abort();//VS被中断，VSC卡顿一会后退出
            throw "Yinlianlei, you have a error on your program.";
            return 1;
        }
        else if(A==B)
        {
            throw 1;
            return 1;
        }
        else
        {
            return 0;
        }
	};
    //bool Judge2(int A,int B) throw(bad_exception);//异常规范
    //bool Judge3(int A,int B) noexcept;//指出函数不会引发异常
};
namespace U_4
{
    bool T_F(int A)
    {
        try
        {
            if(A==0)
            {
                throw A;
            }
            if(A==1)
            {
                throw "Yinlianlei";
            }
        }
        catch(const char *S)
        {
            cout << S << " " << "Yes" << endl;
            throw;//用于在默认情况下返回mian()函数
        }
        catch(int A)
        {
            cout << "Yinlianlei" << " " << A  << endl;
            throw;//将A进行throw并在mian()中进行寻找
        }
    };

    class Test:public std::exception
    {
        private:
            string name;
        public:
            Test(){name="Yinlian";};
            void show()throw(){throw this;};//前面一个throw里可以添加异常类型，检测到会会自动throw给catch进行判断
            ~Test()throw(){cout << 233 << endl;};
            const char* what(){return "Yinlianlei";};
    };

    
};
namespace U_5
{
    class base
    {
        protected:
            string name;
        public:
            base(){name="Yinlianlei";};
            virtual void show(){cout << name << endl;};
    };
    class test_1:public base
    {
        protected:
            int grade;
        public:
            test_1(){grade=0;};
            virtual void show(){base::show();cout << grade << endl;};
    };
    class test_2:public test_1
    {
        private:
            bool sex;
        public:
            test_2(){sex=0;};
            virtual void show(){test_1::show();cout << sex << endl;};
    };
};


#endif
