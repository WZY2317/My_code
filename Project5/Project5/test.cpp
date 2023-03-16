#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;
vector<string> Pocker{ "3","4","5","6","7","8","9","10","J","Q","K","A","2",
                     "joker","JOKER" };
bool IsBomb(vector<string>& pai)
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
void Compare(vector<string>& first, vector<string>& second)
{
    auto p1 = find(Pocker.begin(), Pocker.end(), first[0]);
    auto p2 = find(Pocker.begin(), Pocker.end(), second[0]);
    if (p1 > p2)
    {
        for (int i = 0; i < first.size() - 1; ++i)
            cout << first[i] << " ";
        cout << first[first.size() - 1] << endl;
    }
    else
    {
        for (int i = 0; i < second.size() - 1; ++i)
            cout << second[i] << " ";
        cout << second[second.size() - 1] << endl;
    }
}
void Output(vector<string>& pai)
{
    for (int i = 0; i < pai.size() - 1; ++i)
        cout << pai[i] << " ";
    cout << pai[pai.size() - 1] << endl;
}
void getBigger(string& input)
{
    string input1, input2, temp;
    vector<string> first, second;
    int pos = input.find('-');
    input1 = input.substr(0, pos);
    input2 = input.substr(pos + 1);
    stringstream ss;
    ss << input1;
    while (ss >> temp)
    {
        first.push_back(temp);
    }
    ss.clear(); ss << input2;
    while (ss >> temp)
        second.push_back(temp);
    if (first.size() == second.size())
        Compare(first, second);
    else//牌数目不相同那肯定是得有一个是炸弹，不然输出ERROR
    {
        if (IsBomb(first))//第一个是炸弹
        {
            if (IsBomb(second))//第二个也是炸弹，则直接比较输出
                Compare(first, second);
            else
                Output(first);
        }
        else    //第一个不是炸弹
        {
            if (IsBomb(second))//第二个是炸弹
                Output(second);
            else    //两个都不是炸弹
                cout << "ERROR" << endl;
        }
    }
}
int main()
{
    string input;
    while (getline(cin, input))
    {
        getBigger(input);
    }
}