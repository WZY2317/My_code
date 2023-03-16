#include<iostream>
using namespace std;
bool isCorrNum(int n)
{
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}
int main()
{
	int flag = 0;
	bool g = false;
	
	for (int i = 2;i<5000; i++)
	{
		if (isCorrNum(i))
		{
			for (int j = 1;; j++)
			{
				for (int k = 1; k < 10; k++)
				{
					if (isCorrNum(i + k * j))
					{
						g = true;
					}
					else
					{
						g = false;
						break;
					}
				}
				if (g)
				{
					
					
						flag = j;
						cout << flag << endl;
						break;

					
				}
				else
				{
					break;
				}
			}
		}
	}
	cout << flag << endl;
	return 0;
	/*for (int i = 2; i < 5000; i++)
	{
		if (isCorrNum(i))
		{
			for (int j = 2; j < 1000; j++)
			{
				for (int k = 1; k < 10; k++)
				{
					if (isCorrNum(i + j * k))
					{
						flag++;
					}
					else
					{
						flag = 0; break;
					}
				}
				if (flag == 9)
				{
					cout << j << endl;
					return 0;
				}
			}
		}
	}*/
}