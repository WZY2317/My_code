#include<iostream>
using namespace std;
template<class T>
T Add(const T& left, const T& right)
{
	return left + right;
}
int main()
{
	int a1 = 10, a2 = 9;
	double b1 = 9.1, b2 = 0.3;
	Add(a1, a2);
	Add(b1, b2);
	Add<int>(a1, b1);//������ʽ����ת��������ǿ��ת������Ϊ����ֻ��һ������
}