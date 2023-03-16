#include<iostream>
#include<map>
#include<vector>
#include<string>
#include<utility>
#include<algorithm>
using namespace std;
struct cmp
{
	bool operator()(const pair<string, int>& l, const pair<string, int>& r)
	{
		return l.second > r.second;
	}
};
int main()
{
	string obj;
	
	
	map<string, int> si;
	int i, j;
	while (getline(cin, obj))
	{
		for (int i = 0, j = 0; i <= obj.size(); i++)
		{
			if (obj[i] == ' ' || obj[i] == '.')
			{
				string t = obj.substr(j, i - j);
				if (isupper(t[0]))
					t[0] = tolower(t[0]);
				si[t]++;
				j = i + 1;

			}
		}
		vector<pair<string, int>> v(si.begin(), si.end());
		sort(v.begin(), v.end(), cmp());
		for (int i = 0; i < v.size(); i++)
		{
			cout << v[i].first << ":" << v[i].second << endl;
		}

	}
	
	
}