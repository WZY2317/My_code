#include<vector>
#include<iostream>
using namespace std;
int maxValue(vector<vector<int>>& grid) {
    int row = grid.size();
    int col = grid[0].size();
    vector<int> dp(col + 1);


    for (int i = 1; i <= row; i++)
    {
        for (int j = 1; j <= col; j++)
        {
            dp[j] = max(dp[j], dp[j - 1]) + grid[i - 1][j - 1];

        }
    }
    return dp[col];

}
int main()
{
    vector<vector<int>> r = { {1,3,1},{1,5,1},{4,2,1} };
    int value=maxValue(r);
}