#include<iostream>
using namespace std;
//���캯��˽�о��޷��̳�
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
	//Ϊɶ�����û���ָ�봫���أ����ǿ��Կ������󴫲ε�ʱ����������������麯����ָ�봫�ݸ�����ʱ����ĸ�����麯����ָ�벢û�б仯
	//����ʵ��������͸�����麯����ָ���ֵ�ǲ�ͬ�ģ����ʹ�ö�����ʱ������麯����ָ���Ǵ�����ȥ�ģ����Ծ͵��ø�����麯����
	// 
	//�����麯����ָ�봫������ʱ������ĸ�����麯����ָ��ͱ��������ˣ����Ե�����������麯����ʵ���˶�̬
}