#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
//bool isHeapyear(int year)
//{
//	if ((year % 4 == 0 && year%100!=0) ||year%400==0)
//	{
//		return true;
//	}
//	return false;
//}
//int main()
//{
//	int year, month, day;
//	vector<int> Noryear = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
//	vector<int> heapyear = {0, 31,29,31,30,31,30,31,31,30,31,30,31 };
//	cin >> year >> month >> day;
//	int num = 0;
//	if (isHeapyear(year))
//	{
//		for (int i = 1; i < month; i++)
//		{
//			num += heapyear[i];
//		}
//		num += day;
//	}
//	else
//	{
//		for (int i = 1; i < month; i++)
//		{
//			num += Noryear[i];
//		}
//		num += day;
//	}
//	cout << num << endl;
//
//}
typedef long long ll;
int n;
int res;
void DFS(vector<int>& nums, int index, int sum, int mul)
{
	for (int i = index; i < n; i++)
	{
		if (i > index && nums[i] == nums[i - 1])
			continue;
		sum += nums[i];
		mul *= nums[i];
		if (sum > mul)
		{
			res += 1;
			DFS(nums, i + 1, sum, mul);

		}
		else
			break;
		sum -= nums[i];
		mul /= nums[i];
	}
	return ;
}
int main()
{
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		cin >> nums[i];
	}
	sort(nums.begin(), nums.end());
	res = 0;
	if (nums[0] == 1)
	{
		DFS(nums, 1, 1, 1);
	}
	DFS(nums, 0, 0, 1);
	cout << res << endl;
}