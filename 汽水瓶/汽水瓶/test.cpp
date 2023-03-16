#include<iostream>
using namespace std;

int Bottle;
int num = 0;
int main()
{
	
	while (cin >> Bottle)
	{
		if (Bottle == 0)
			break;
		while (Bottle > 1)
		{

			Bottle -= 3;
			num += 1;
			Bottle++;

		}
		cout << num << endl;
		num = 0;
	}
		
	

}