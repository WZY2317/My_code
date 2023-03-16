#include<iostream>
using namespace std;

int main()
{
    int n, m;
    int num = 0;
    char str[100][100] = { 0 };
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> str[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (str[i][j] == '*')
                cout << '*';
            if (str[i][j] == '?')
            {
                if (str[i - 1][j] == '*')
                    num++;
                if (str[i - 1][j - 1] == '*')
                    num++;
                if (str[i - 1][j + 1] == '*')
                    num++;
                if (str[i][j + 1] == '*')
                    num++;
                if (str[i][j - 1] == '*')
                    num++;
                if (str[i + 1][j] == '*')
                    num++;
                if (str[i + 1][j + 1] == '*')
                    num++;
                if (str[i + 1][j - 1] == '*')
                    num++;
                cout << num;

            }
            num = 0;

        }
        cout << endl;
    }
}