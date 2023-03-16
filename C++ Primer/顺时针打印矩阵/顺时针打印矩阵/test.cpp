#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        if (row == 0 || col == 0)
            return {};
        vector<int> res;
        int left = 0, right = col - 1;
        int top = 0, bottom = row - 1;
        while (left <= right && top <= bottom)
        {
            for (int i = left; i <= right; i++)
            {
                
                res.push_back(matrix[top][i]);
            }
            for (int j = top + 1; j <= bottom; j++)
            {
               
                res.push_back(matrix[j][right]);
            }
            for (int k = right-1; k >=left ; k--)
            {
                if(bottom!=top)
                res.push_back(matrix[bottom][k]);
            }
            for (int g = bottom-1; g > top; g--)
            {
                if(left!=right)
                res.push_back(matrix[g][left]);
            }
            left++;
            right--;
            top++;
            bottom--;
        }
        return res;
    }
   

};
int main()
{
    vector<vector<int>> r = { {1, 2, 3, 4} ,{5, 6, 7, 8},{9, 10, 11, 12} };
    Solution s;
    s.spiralOrder(r);
}