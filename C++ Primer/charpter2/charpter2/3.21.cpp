#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> vv(10, 42) ;
	vector<int>::iterator it;
	for (auto it = vv.begin(); it != vv.end(); it++)
	{
		cout << *it << endl;
	}
}