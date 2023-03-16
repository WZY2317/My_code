#include<iostream>
#include<vector>
#include<string>
using namespace std;
int isNumberRoot(int n)
{
	
	
		int j = 0;
		vector<int> V;

		while (n)
		{
			j = n % 10;
			n = n / 10;
			V.push_back(j);
		}
		int sum = 0;
		for (auto i = V.begin(); i < V.end(); i++)
		{
			sum += *i;
		}
		if (sum >= 10)
		{
			isNumberRoot(sum);
		}
		return sum;
	
	
		
	
}
int main()
{
	int n;
	cin >> n;
	
		
	
		
		cout << isNumberRoot(n) << endl;
	
	
}