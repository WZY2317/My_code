#include<iostream>
#include<string>
using namespace std;
class person
{


public:
	person()
	{
		count++;
	}
	person(const char* name)
		:_name(name)

	{
	
		printf("person()\n");
	}
	~person()
	{
		printf("~person()\n");
	}
	person(const person& p)
		:	_name(p._name)
	{
		printf("const person& p\n");
	}
	person& operator=(const person& p)
	{
		cout << "Person operator=(const Person& p)" << endl;
				if (this != &p)
					_name = p._name;
		
				return *this;
	}
	
public:
	
	string _name;
	static int count;
};
int person::count = 0;
class student :public person
{
public:
	student(const char* name="zhangsan", int num=1)
		:person(name)
		, _num(num)
	{

	}
	student(const student& s)
		:person(s)
		,_num(s._num)
	{

	}
	student& operator=(const student& s)
	{
		if (this != &s)
		{
			person::operator=(s);
			_num = s._num;
		}
		return *this;
	}
	//析构函数的名字会统一处理成destructor，所以子类的析构函数和父类的就会构成隐藏了
	~student()
	{
		//person::~person();
	}
	//由于栈的后进先出原则，编译器会先调用子类的析构函数，在子类的析构函数结束时会自动调用父类的析构函数
	//这样才能先析构子类再析构父类
	/*void Print()
	{
		cout << " 姓名：" << _name << endl;
		cout << person::_num << endl;
	}*/
public:
	int _num=999;
	//string s = "hello";
};
class A
{
public:
	void fun()
	{
		cout << "func()" << endl;
	}
};
class B :public A
{
public:
	void fun(int i)
	{
		//A::fun();
		cout << "func(int i)->" << i << endl;//构成函数隐藏，A的函数被B的隐藏了
	}
};
int main()
{
	/*person P;
	student S;
	S.Print();*/
	/*B b;
	b.A::fun();*/
	person p;
	person p2;
	student s;
	student s2;
	cout << person::count << endl;
	
	/*student s1(s);
	student s3("jck", 18);
	s1 = s3;*/

}