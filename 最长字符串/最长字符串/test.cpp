#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    int MoreThanHalfNum_Solution(vector<int> numbers) {
        int arr[50000] = { 0 };
        for (int i = 0; i < numbers.size(); i++)
        {
            arr[numbers[i]]++;
        }
        for (int i = 1; i < 500000; i++)
        {
            if (arr[i] > (numbers.size() / 2))
            {
                return i;
            }
        }


    }
};
int main()
{
    vector<int> arr;
    for (int i = 0; i < arr.size(); i++)
    {
        cin >> arr[i];
    }
    int res = Solution::MoreThanHalfNum_Solution(arr);
}
//int main()
//{
//    string s;
//    int maxlength = 0;
//    char str[255] = { 0 };
//    cin >> s;
//    int i = 0;
//    int length = 0;
//    int begin = 0;
//    while (i < s.size())
//    {
//
//        while (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9')
//        {
//
//            i++;
//            length++;
//        }
//        i++;
//        if (length > maxlength)
//        {
//            maxlength = length;
//            begin = i - maxlength - 1;
//        }
//        length = 0;
//    }
//    for (int j = begin; j < begin + maxlength; j++)
//    {
//        cout << s[j];
//    }
//}