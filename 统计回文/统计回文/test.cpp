#include<iostream>
#include<vector>
#include<string>
using namespace std;
int StrToInt(string str) {
    int res = 0;
    if (str[0] == '+')
    {
        for (int i = str.size()-1; i >= 1; i--)
        {
            if (str[i] >= '0' && str[i] <= '9')
                res += (str[i]-'0') * pow(10, str.size() - 1 - i);
            else
                return 0;
        }
        return res;
    }
    else if (str[0] == '-')
    {
        for (int i = str.size()-1; i >= 1; i--)
        {
            if (str[i] >= '0' && str[i] <= '9')
                res += (str[i] - '0') * pow(10, str.size()-1 - i);
            else
                return 0;
        }
        return res * -1;
    }
    else if (str[0] >= '0' && str[0] <= '9')
    {
        for (int i = str.size()-1; i > 01; i--)
        {
            if (str[i] >= '0' && str[i] <= '9')
                res += (str[i] - '0') * pow(10, str.size()-1 - i);
            else
                return 0;
        }
        return res;
    }
    else {
        return 0;
    }
}


int main()
{
    string A;
    cin >> A;
    int res = StrToInt(A);
    cout << res << endl;
	

}