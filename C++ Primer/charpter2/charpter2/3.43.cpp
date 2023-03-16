#include<iostream>
using namespace std;
int main()
{
	int ia[3][4] = { 0 };
	for (int (&row)[4] : ia)
	{
		for (int(&col) : row)
		{

		}
	}
	for (auto& e : ia)
	{
		for (auto& a : e)
		{

		}
	}
	for (int(*p)[4] = ia; p != p + 3; p++)
	{
		for (int* q = *p; q != q + 4; q++)
		{

		}
	}
	for (auto p = ia; p != p + 3; p++)
	{
		for (auto q = *p; q != *p + 4; q++)
		{

		}
	}
}