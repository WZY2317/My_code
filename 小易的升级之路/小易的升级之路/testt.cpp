#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s;
    cin >> s;
    int num = 0;
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = 0; j < s.size(); j++)
        {
            if (s[i] == s[j])
            {
                num++;
            }
         }
        if (num == 1)
        {
            cout << s[i] << endl;
            return 0;
        }
        num = 0;
    


    }
    cout << -1 << endl;
}