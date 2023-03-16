#include<iostream>
using namespace std;
void Fun(int&& x) { cout << "右值引用" << endl; }
void Fun(const int&& x) { cout << "const 右值引用" << endl; }
template<typename T>
void PerfectForward(T&& t)
{
	Fun(t);
}
int main()
{
	PerfectForward(10);//右值
	int a;
	PerfectForward(a);
	PerfectForward(move(a));
	const int b = 8;
	PerfectForward(b);
	PerfectForward(move(b));
}