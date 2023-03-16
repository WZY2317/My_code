#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
const int N = 200000;
int n;
struct line
{
	double k, b;
	bool operator<(const line& t)
	{
		if (k != t.k)
			return k < t.k;
		return b < t.b;
	}

}l[N];
int main()
{
	for(int x1=0;x1<20;x1++)
		for (int y1 = 0; y1 < 21; y1++)
			for(int x2 = 0; x2 < 20; x2++)
				for (int y2 = 0; y2 < 21; y2++)
				{
					if (x1 != x2)
					{
						double k = (y1 - y2) / (x1 - x2);
						double b = y1 - k*x1;
						l[n++] = { k,b };
					}
						
				}
	sort(l, l + n);
	int res = 1;
	for (int i = 1; i < n; i++)
	{
		if (fabs(l[i].k - l[i + 1].k) < 1e-8 || fabs(l[i].b - l[i + 1].b) < 1e-8)
		{
			res++;
		}
	}
	cout << res + 20 << endl;



}