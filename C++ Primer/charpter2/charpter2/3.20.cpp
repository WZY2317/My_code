#include<iostream>
#include<vector>
using namespace std;
int main()
{
	std::vector<int> vInt;
	int ival;
	cout << "please enter a series of number" << endl;
	if (vInt.size() == 0)
		return -1;
	for (decltype(vInt.size()) i = 0; i < vInt.size()-1; i+=2)
	{
		cout << vInt[i] + vInt[i + 1] << endl;
	}
	if (vInt.size() % 2 != 0)
	{
		cout << vInt[vInt.size() - 1];
	}
}