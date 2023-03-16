#include<iostream>
using namespace std;
int Array[100001] = {
0
};
int Maxnum[100001] = { 0 };
void getMaxlength(int array)
{
	
}
int main()
{
	int N;
	int flag = 0;
	int j = 1;
	cin >> N;
	while (1)
	{
		for (int i = 1; i <= N; i++)
		{
			Array[i]++;
		}

		Array[j]=0;
		
		

		if (flag == 1)
		{
			j--;
			flag == 0;
		}
		if (flag != 1)
		{
			j++;
		}
		
		if (j == N)
		{
			flag == 1;
		}
		//
		
		

	}
	

}