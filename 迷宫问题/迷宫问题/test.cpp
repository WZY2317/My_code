#include<iostream>
#include<vector>
using namespace std;
class solution
{
	int N, M;
	vector<vector<int>> maze;//迷宫矩阵
	vector<pair<int, int>> path_cur;//当前路径
	vector<pair<int, int>> path_best;
	void deal(int i, int j)
	{
		maze[i][j] = 1;//已经走过的不能再走了，1
		path_cur.push_back({i,j});
		if (N-1==i && j = M - 1)
		{
			if (path_best.empty() || path_cur.size() < path_best.size())
			{
				path_best = path_cur;
			}
		}
		if (i - 1 >= 0 && maze[i - 1][j] == 0)
		{
			deal(i - 1, j);
		}
		if (j - 1 >= 0 && maze[i][j - 1] == 0)
		{
			deal(i, j - 1);
		}
		if (i + 1 < N && maze[i + 1][j] == 0)
		{
			deal(i + 1, j);
		}
		if (j + 1 < M && maze[i][j + 1] == 0)
		{
			deal(i, j + 1);
		}
		maze[i][j] = 0;

	}
};
int main()
{

}