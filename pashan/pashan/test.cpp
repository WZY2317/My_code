#include<iostream>
#include<stdbool.h>
#include<algorithm>
#include<math.h>
#include<stdio.h>
using namespace std;
int n;
struct node {
	int x;
	int y;
	int z;
}a[50005];
bool cmp(node a, node b)
{
	
		return a.z < b.z;
}
double hign(node a, node b)
{
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) + (a.z - b.z) * (a.z - b.z));
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i].x >> a[i].y >> a[i].y;
	}
	sort(a, a + n, cmp);
	double res = 0;
	for (int i = 0; i < n-1; i++)
	{
		res += hign(a[i], a[i+1]);
	}
	printf("%0.3lf", res);


}