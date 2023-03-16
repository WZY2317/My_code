#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
vector<string> Pocker{ "3","4","5","6","7","8","9","10","J","Q","K","A","2",
                     "joker","JOKER" };
bool IsBomb(vector<string>& api)
{


        if (pai.size() == 2)//如果只有两张必须得是双王
        {
            if (pai[0] == "joker" || pai[0] == "JOKER")
                return true;
            else
                return false;
        }
        else if (pai.size() == 4) //不然只能是四张
        {
            return true;
        }
        else
            return false;
}

int main()
{
}