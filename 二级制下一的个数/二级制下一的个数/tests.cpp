#include<iostream>
using namespace std;


//1010 1101
//0000 0001->0
int main()
{
	int n;

	cin >> n;
	int num = 0;
	while (n)
	{
		if (n & 1 == 1)
		{
			num++;
		}
		n >>= 1;
	}
	cout << num << endl;

}