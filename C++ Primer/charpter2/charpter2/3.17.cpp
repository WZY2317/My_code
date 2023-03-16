#include<iostream>
#include<vector>
#include<string>
using std::vector;
using std::string;
int main()
{
	vector<string> vstring;
	string s;
	while (std::cin >> s)
	{
		vstring.push_back(s);
	}
	for (auto e : vstring)
	{
		for (auto c : e)
		{
			c = toupper(c);
		}
		std::cout << e << std::endl;
	}
}