#include<iostream>
#include<vector>
using namespace std;
int m;
int n;

//int road[30][3];//����·��
//bool f[10][10];//��ǵ��Ƿ��߹�
//int fx[5] = {0,0,0,-1,1};//��¼����
//int fy[5] = {0,1,-1,0,0};
//void print(int k)
//{
//
//}
//void dfs(int x, int y, int k)
//{
//	road[k][1] = x;
//	road[k][2] = y;
//	if (x == n && y == n)
//	{
//		print(k);
//		return;
//	}
//	//���Բ�ͬ�ķ���
//	for (int i = 1; i <= 4; i++)
//	{
//		int tx = x + fx[i];
//		int ty = y + fy[i];
//		//����µķ���ɴ����û�з��ʹ�
//		if (tx <= n && ty <= n && f[tx][ty] == false && tx > 1 && ty > 1)
//		{
//			f[tx][ty] = true;
//			dfs(tx, ty, k + 1);
//			f[tx][ty] = false;
//		}
//		
//	}
//
//}
//int main()
//{
//	cin>> n;
//	f[1][1] = true;
//	dfs(1, 1, 1);
//}

int fx[3] = { 0,1,0 };
int fy[3] = { 0,0,1 };
bool f[101][101];
static int aray[110][110] = { 0 };
vector<int> res;
void dfs(int x, int y, int k)
{
	int j = 0;
	k += aray[x][y];
	if (x == m && n == y)
	{
		res.push_back(k);
		
		return;
	}
	for (int i = 1; i <= 2; i++)
	{
		int tx = x + fx[i];
		int ty = y + fy[i];
		if (tx >= 1 && tx <= n && ty >= 1 && ty <= n && f[tx][ty] == false)
		{
			f[tx][ty] = true;

			dfs(tx, ty, k );
			f[tx][ty] = false;
		}

	}
}
int main()
{
	
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> aray[i][j];
		}
	}
	dfs(1, 1, 0);
	vector<int>::iterator a;
	int max = INT32_MIN;
	for (a = res.begin(); a <= res.end(); a++)
	{
		if (*a > max)
			max = *a;
	}
	cout << max << endl;
}
