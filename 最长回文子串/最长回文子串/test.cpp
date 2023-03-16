#include<iostream>
#include<string>
#include<vector>
#include<set>
using namespace std;

    string longestPalindrome(string s) {
        int len = s.size();
        bool dp[10][10];
        for (int i = 0; i < len; i++)
        {
            dp[i][i] = true;
        }
        if (len < 2)
            return s;
        int maxL = 1;
        int index = 0;
        for (int l = 2; l <= len; l++)
        {
            for (int i = 0; i < len; i++)
            {
                int j = i + l - 1;
                if (j >= len)
                    break;
                if (s[i] != s[j])
                    dp[i][j] = false;
                else
                {
                    if (j - i < 3)
                        dp[i][j] = true;
                    else
                        dp[i][j] = dp[i + 1][j - 1];
                }
                if (j - i + 1 > maxL && dp[i][j])
                    maxL = j - i + 1;
                index = i;
            }
        }
        return s.substr(index, maxL);
    }


    vector<string> generateParenthesis(int n) {
        if (n == 0)
            return vector<string>();
        vector<vector<string>> dp = vector<vector<string>>(n + 1);
        set<string> rr = set<string>();
        dp[1].push_back("()");
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < dp[i - 1].size(); j++)
            {
                string base = dp[i - 1][j];
                for (int k = 0; k < base.size(); k++)
                {
                    string left = base.substr(0, k);
                    string right=base.substr(k);
                    string add = left + "()" + right;
                    if (rr.insert(add).second)
                    {
                        dp[i].push_back(add);
                    }
                }

            }
        }
        return dp[n];
    }

int main()
{
    vector<string> res = generateParenthesis(3);
   
}