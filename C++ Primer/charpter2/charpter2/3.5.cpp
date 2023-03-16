#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s;
	string os;
	while (cin >> s)
	{
		os += s;
	}
	cout << os << endl;
	while (cin >> s)
	{
		os +=s+" ";
	}
	cout << os << endl;

	
}