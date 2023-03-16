#include<iostream>
using namespace std;
//构造函数私有就无法继承
class Base
{
public:
	virtual void func1()
	{
		cout << "Base::func1()" << endl;
	}
	virtual void func2()
	{
		cout << "Base::func2()" << endl;
	}
	void func3()
	{
		cout << "Base::func3()" << endl;
	}
private:
	int _b = 1;
};
class Derive :public Base
{
public:
	virtual void func1()
	{
		cout << "Derive::func1()" << endl;
	}
private:
	int _d=2;
	
};
int main()
{
	/*Base A;
	printf("%d", sizeof(A));*/
	
	Base B;
	
	Derive d;
	B = d;
	Base& b=d;
	return 0;
	//为啥是引用或者指针传参呢，我们可以看到对象传参的时候，这里的子类对象的虚函数表指针传递给父类时这里的父类的虚函数表指针并没有变化
	//但是实际上子类和父类的虚函数表指针的值是不同的，如果使用对象传入时传入的虚函数表指针是穿不过去的，所以就调用父类的虚函数了
	// 
	//子类虚函数表指针传给父类时，这里的父类的虚函数表指针就变成子类的了，所以调用了子类的虚函数，实现了多态
}