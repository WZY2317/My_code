#include<iostream>
using namespace std;
void Fun(int&& x) { cout << "��ֵ����" << endl; }
void Fun(const int&& x) { cout << "const ��ֵ����" << endl; }
template<typename T>
void PerfectForward(T&& t)
{
	Fun(t);
}
int main()
{
	PerfectForward(10);//��ֵ
	int a;
	PerfectForward(a);
	PerfectForward(move(a));
	const int b = 8;
	PerfectForward(b);
	PerfectForward(move(b));
}