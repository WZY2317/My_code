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
	//�������������ֻ�ͳһ�����destructor��������������������͸���ľͻṹ��������
	~student()
	{
		//person::~person();
	}
	//����ջ�ĺ���ȳ�ԭ�򣬱��������ȵ�������������������������������������ʱ���Զ����ø������������
	//����������������������������
	/*void Print()
	{
		cout << " ������" << _name << endl;
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
		cout << "func(int i)->" << i << endl;//���ɺ������أ�A�ĺ�����B��������
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