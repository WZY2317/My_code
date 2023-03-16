#include<iostream>
#include<string>
using namespace std;
int maxcommonstr(string s1, string s2)
{
	string s3 = (s1.length() <= s2.length() ? s1 : s2);
	string s4 = (s1.length() >= s2.length() ? s1 : s2);
	int sum = 0;
	int max = 0;
	for (int i = s3.length(); i > 0; i--)
	{
		for (int j = 0; j <= s3.length() - i; j++)
		{
			if (s4.find(s3.substr(j, i)) != string::npos)
			{
				sum = s3.substr(j, i).size();
				if (sum > max)
				{
					max = sum;
				}
			}
		}
	}
	return sum;
}

int main()
{
	string s1, s2;
	while (cin >> s1 >> s2)
	{
		cout << maxcommonstr(s1, s2);
	}
	return 0;
}