#include<iostream>
#include<stdbool.h>
#include<algorithm>
using namespace std;
int n;
struct node {
	string name;
	int year, month, day;
	int level;//¼ÇÂ¼´ÎÐò
}a[105];

bool cmp(node a,node b)
{
	if (a.year < b.year)
		return true;
	else if (a.year > b.year)
		return false;
	else {
		if (a.month < b.month)
			return true;
		else if (a.month > b.month)
			return false;
		else
		{
			if (a.day < b.day)
				return true;
			else if (a.day > b.day)
				return false;
			else
			{
				if (a.level < b.level)
					return true;
			}
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].name >> a[i].year >> a[i].month >> a[i].day;
		a[i].level = i;
	}
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++)
	{
		cout << a[i].name << endl;
	}
}