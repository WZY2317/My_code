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
		cout << "���첻����" << endl;
		
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
		cout << "��������ҵ����г�" << endl;
	}
	virtual ~officials()
	 {
		 cout << "~offocials" << endl;
	 }
};
void Func(OrdinaryPerson* people)//����ͨ����������û���ָ���������麯��
{
	people->FindBike();
}
void Func(OrdinaryPerson people)//�������ͨ����������û���ָ�룬���ﴫ�ݵ�ԭ�����õ���Ƭ
{
	people.FindBike();
}
//void Func(OrdinaryPerson& people)//����ͨ����������û���ָ���������麯��
//{
//	people.FindBike();
//}
int main()
{
	OrdinaryPerson Tom;
	
	officials clerk;
	Func(Tom);
	Func(clerk);
	//�������������������ǲ����麯����������ȷ��������������
	//����Ϊ���ﲢ����ͨ��ָ������õ��õģ��������ɶ�̬
	//��̬����Ķ���������˸���ָ�������ô��Ҫ�����������麯��
	//OrdinaryPerson* p1 = new OrdinaryPerson;//operator+ new ���캯��
	//OrdinaryPerson* p2 = new officials;
	//delete p1;//p1-> destructor
	//delete p2;//p2->destructor���ﹹ���˶�̬������Ϊ��ͨ��ָ������ˣ���������ɶ�̬��
	//��ô�����p1��p2���ǻ���ģ���Ҫ���û��������������Ȼ��ʵ������������
	//��������+delete 
	/*Func(Tom);
	Func(clerk);*/

}