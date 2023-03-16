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
    if (pai.size() == 2)//���ֻ�����ű������˫��
    {
        if (pai[0] == "joker" || pai[0] == "JOKER")
            return true;
        else
            return false;
    }
    else if (pai.size() == 4) //��Ȼֻ��������
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
    else//����Ŀ����ͬ�ǿ϶��ǵ���һ����ը������Ȼ���ERROR
    {
        if (IsBomb(first))//��һ����ը��
        {
            if (IsBomb(second))//�ڶ���Ҳ��ը������ֱ�ӱȽ����
                Compare(first, second);
            else
                Output(first);
        }
        else    //��һ������ը��
        {
            if (IsBomb(second))//�ڶ�����ը��
                Output(second);
            else    //����������ը��
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