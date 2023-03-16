#include<iostream>
using namespace std;
int leapyear[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
int yearl[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
bool isMonday(int n)
{
	if (n == 0)
		return true;
	if (n % 7 == 0)
		return true;
	return false;
}
bool isyearbegin(int n )
{
	if (n == 0)
		return true;
	int day = 1;
	for (int year = 2000; year <= 2020; year++)
	{
		if (year % 4 == 0)
		{
			for (int i = 0; i < 12; i++)
			{
				day += leapyear[i];
				if (n == day)
					return true;
			}
		}
		else
		{
			for (int i = 0; i < 12; i++)
			{
				day += yearl[i];
				if (n == day)
					return true;

			}
		}
		return false;
	}
	
	
}
int day = 4 * 366 + 16 * 365 + 366 - 31 - 30 - 31 + 1;
int main()
{
	
	int n = 0;
	int cnt = 1;
	while (n <= day)
	{
		n++;
		cnt++;
		if (isMonday(n) || isyearbegin(n))
		{
			cnt++;
		}

	}
	cout << cnt;
}