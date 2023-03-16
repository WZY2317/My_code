#include<iostream>
using namespace std;
//第一题1478第二题是5

int main()
{
	/*int a = 2 * 1 + 2 * 9 + 0 * 81 + 2 * 81 * 9;
	printf("%d", a);
	return 0;*/
	int a, b, n;
	int num = 0;
	int k = 0;
	cin >> a >> b >> n;
	while (num < n)
	{
		for (int i = 0; i < 5; i++)
		{
			if (num < n)
			{
				num += a;
				k++;
			}
			
		}
		for (int i = 0; i < 2; i++)
		{
			if (num < n)
			{
				num += b;
				k++;
			}
			
		}
	}
	cout << k << endl;

}