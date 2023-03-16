#include<iostream>
#include<stdio.h>
using namespace std;
//class A
//{
//public:
//	void f()
//	{
//		cout << "A" << endl;
//	}
//};
//class B :public A
//{
//public:
//	virtual void f()
//	{
//		cout << "B" << endl;
//	}
//};
	
struct A
{
	void foo() {
		printf("foo");
	}
	virtual void bar()
	{
		printf("bar");
	}
	A()
	{
		printf("bar()");
	}

};
struct B :A
{
	void foo()
	{
		printf("b_foo");
	}
	void bar()
	{
		printf("b_bar");
	}
};
int main()
{
	A* p = new B;
	p->foo();
	p->bar();
}
	