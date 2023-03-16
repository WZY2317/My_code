#include<iostream>
int a[25];
int n, r;
using namespace std;
int res = 0;
bool isPrime(int x)
{
	if (x < 2)
		return false;
	for (int i = 2; i * i < x; i++)
	{
		if (x % i == 0)
			return false;
	}
	return true;

}
void dfs(int m, int sum, int startx)
{
	if (m == k)
	{
		if (isPrime(sum))
		{
			res++;
		}
	}
	for (int i = startx; i < n; i++)
	{
		dfs(m + 1, a[i] + sum, i + 1);
	}
	return;
}
int main()
{
	
	cin >> n >> r;
	for (int i = 0; i < n; i++)
		scanf_s("%d", &a[i]);//Ñ­»·¶ÁÈë
	dfs(0, 0, 0);
	printf("%d", res);

}