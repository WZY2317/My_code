#include<iostream>
using namespace std;
int a[1050][1050] = { 0 };
void di(int length, int r, int c)
{
	if (length == 2)
	{
		a[r][c] = 0;
		return;
	}
	for (int i = r ; i <r+ length / 2; i++)
	{
		for (int j = c; j <c+ length/2; j++)
		{
			a[i][j] = 0;
		}
	}
	di(length / 2, r + length/2, c);
	di(length / 2, r + length / 2, c + length / 2);
	di(length / 2, r, c + length / 2);
	
}

int main()
{
	int n;
	
	cin >> n;
	int length = 1;
	for(int i = 1; i <= n; i++)
	{
		length *= 2;
	}
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
			a[i][j] = 1;
	}
	di(length,0 , 0);
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < length; j++)
			cout << a[i][j] << " ";
		cout << endl; //输出，此处可以避免输出行尾空格
	}
	return 0;
}