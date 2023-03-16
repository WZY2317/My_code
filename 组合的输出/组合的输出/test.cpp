#include<iostream>
#include<iomanip>
using namespace std;
int n, r;
int a[21];
void DFS(int k)
{
	if (k > r)
	{
		for (int i = 1; i <= r; i++)
			cout << setw(3) << a[i];
		cout << endl;
		return;
	}
	for (int i= a[k - 1] + 1; i <= n; i++)
	{
		a[k] = i;
		DFS(k + 1);
	}
}
int main()
{
	cin >> n >> r;
	DFS(1);

}