#include<iostream>
using namespace std;
int A, B, C, a, b, c, num;
int flag = 0;
int n[10] = { 0 };
void cai(int x)
{
	while (x != 0)
	{
		num = x % 10;
		x = x / 10;
		n[num]++;
	}
}
int main()
{
	cin >> A >> B >> C;
	for (int i = 1; i <= 9; i++)
	{
		for (int j = 1; j <= 9; j++)
		{
			for (int k = 1; k <= 9; k++)
			{
				a = 100 * i + 10 * j + k;
				b = (a / A) * B;
				c = (a / A)* C;
				cai(a);
				cai(b);
				cai(c);
				if ( n[1] == 1 && n[2] == 1 && n[3] == 1 && n[4] == 1 && n[5] == 1 && n[6] == 1 && n[7] == 1 && n[8] == 1 && n[9] == 1)
				{
					cout << a << " " << b << " " << c << " " << endl;
					flag++;

				}
				for (int h = 1; h <= 9; h++)
				{
					n[h] = 0;
				}

			}
		}
	}
	if (flag == 0)
		cout << "No!!!" << endl;
}