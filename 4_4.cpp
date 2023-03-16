#include <iostream>
#include<vector>
using namespace std;
typedef long long ll;
int main()
{
	ll n=2021041820210418;
	vector<ll> d;
	for(ll i=1;i*i<=n;i++)
	{
		if(n%i==0)
		{
			d.push_back(i);
			if(n/i!=i)
			d.push_back(n/i);
		}
	}
	int ans=0;
	vector<ll>::iterator a,b,c;
	for(a=d.begin();a!=d.end();a++)
	{
			for(b=d.begin();b!=d.end();b++)
			
			{
					for(c=d.begin();c!=d.end();c++)
					{
						if((*a)*(*b)*(*c)==n)
						{
							ans++;
						}
					}
			}
	}
	cout<<ans;
	
	
}
