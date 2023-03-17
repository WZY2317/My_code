#include<iostream>
#include<algorithm>

#include<vector>
using namespace std;
void nextPermutation(vector<int>& nums) {
    int n = nums.size();

    for (int i = n - 1; i >= 1; i--)
    {

        if (nums[i] > nums[i - 1])
        {
            for (int j = n - 1; j > i - 1; j--)
            {
                if (nums[j] > nums[i - 1])
                {
                    swap(nums[j], nums[i - 1]);
                    sort(nums.begin() + i + 1, nums.end());
                    return;
                }
            }

        }


        if (i == 1)
        {
            reverse(nums.begin(), nums.end());
        }

    }

}
int main()
{
    vector<int> nums = { 1,1,5 };
    nextPermutation(nums);
}