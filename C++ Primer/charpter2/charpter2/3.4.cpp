#include<iostream>
#include<string>
using namespace std;
int main()
{
	
	string s1, s2;
	string s;
	cin >> s1 >> s2;
	if (s1 == s2)
	{
		cout << "same" << endl;
	}
	else
	{
		s = s1 > s2 ? s1 : s2;
		cout << s << endl;
	}
	if (s1.size() == s2.size())
	{
		s = s1.size() > s2.size() ? s1 : s2;
		cout << s << endl;
	}
}