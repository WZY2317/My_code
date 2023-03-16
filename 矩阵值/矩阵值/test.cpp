#include<iostream>
#include<vector>
#include<map>
using namespace std;
void setZeroes(vector<vector<int>>& matrix) {
    int m = matrix.size();
    int n = matrix[0].size();
    map<int, int> _map;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                _map.insert(make_pair(i, j));
            }
        }
    }
    map<int, int>::iterator iter = _map.begin();
    while (iter != _map.end()) {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == iter->first || j == iter->second)
                {
                    matrix[i][j] = 0;
                }
            }
        }
        iter++;
    }

}
int main()
{
    //vector<vector<int>> matrix = { {1,1,1} ,{1,0,1},{1,1,1} };
    vector<vector<int>> matrix = { {0,1,2,0} ,{3,4,5,2},{1,3,1,5} };
    setZeroes(matrix);
}