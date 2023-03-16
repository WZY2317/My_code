#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int N;
	int arr[100];
	
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + N);
	int prev ;
	for (int i = 0; i < N; i++)
	{
		if (arr[i] == prev)
			continue;
		else
		{
			prev = arr[i];
			cout << arr[i] << " ";
		}
	}
}
