#include <iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
    // 请在此输入您的代码
    int N; cin >> N;
    int arr[100][100] = { 0 };
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cin >> arr[i][j];
        }
    }
    for (int i = 1; i < N; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0)
            {
                arr[i][j] = arr[i - 1][j] + arr[i][j];

            }
            else if (i == j)
            {
                arr[i][j] = arr[i - 1][j - 1] + arr[i][j];
            }
            else
            {
                arr[i][j] = max(arr[i - 1][j - 1], arr[i - 1][j]) + arr[i][j];
            }
        }
        
    }
    int maxN = arr[N - 1][0];
    for (int i = 0; i < N; i++)
    {
        if (arr[N - 1][i] > maxN)
            maxN = arr[N - 1][i];
    }
    cout << maxN << endl;
    return 0;
}