#include<iostream>
using namespace std;
class A{};
class B :public A
{};
class person {
public:virtual A* f()

{
	return new A;
}
};
class student :public person
{
public:virtual B* f()
{
	return new B;
	}
};
class OrdinaryPerson
{
public:
	virtual void FindBike()
	{
		cout << "警察不理你" << endl;
		
	}
	 virtual ~OrdinaryPerson()
	{
		cout << "~OrdinaryPerson" << endl;
	}
};
class officials :public OrdinaryPerson
{
public:
	 virtual void FindBike()//
	{
		cout << "警察帮你找到自行车" << endl;
	}
	virtual ~officials()
	 {
		 cout << "~offocials" << endl;
	 }
};
void Func(OrdinaryPerson* people)//必须通过基类的引用或者指针来调用虚函数
{
	people->FindBike();
}
void Func(OrdinaryPerson people)//如果不是通过基类的引用或者指针，这里传递的原理利用的切片
{
	people.FindBike();
}
//void Func(OrdinaryPerson& people)//必须通过基类的引用或者指针来调用虚函数
//{
//	people.FindBike();
//}
int main()
{
	OrdinaryPerson Tom;
	
	officials clerk;
	Func(Tom);
	Func(clerk);
	//在这里无论析构函数是不是虚函数，都会正确调用析构函数，
	//是因为这里并不是通过指针或引用调用的，并不构成多态
	//动态申请的对象，如果给了父类指针管理，那么需要析构函数是虚函数
	//OrdinaryPerson* p1 = new OrdinaryPerson;//operator+ new 构造函数
	//OrdinaryPerson* p2 = new officials;
	//delete p1;//p1-> destructor
	//delete p2;//p2->destructor这里构成了多态，是因为它通过指针调用了，如果不构成多态，
	//那么这里的p1和p2都是基类的，都要调用基类的析构函数，然而实际情况并非如此
	//析构函数+delete 
	/*Func(Tom);
	Func(clerk);*/

}