
#include<iostream>
#include<string>
using namespace std;
int main()
{
    string str;
    while (cin >> str)
    {
        int left = 0, right = str.size() - 1;
        while (left < right)
        {
            swap(str[left++], str[right++]);
        }
        cout << str << endl;
    }

}