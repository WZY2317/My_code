
#include<iostream>
#include<vector>
using namespace std;

void test_vector()
{
	vector<int> v1;

}
void test_vector2()
{
	vector<int > v;
	v.push_back(1);
}
int mian()
{
	vector<vector<int>> vv;
	vv.resize(5);
	for (size_t i = 0; i < 5; ++i)
	{
		vv[i].resize(i + 1);
		vv[i][0] = vv[i][vv[i].size() - 1] = 1;

		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; i < vv[i].size(); ++j)
			{
				if (vv[i][j] == 0)
				{
					vv[i][j] = vv[i - 1][j]  + vv[i-1][j - 1];
				}
			}
		}
		return 0;
}