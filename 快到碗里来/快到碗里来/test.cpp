#include<iostream>
using namespace std;
double C(int r)
{
    return r * r * 3.14;
}
int main()
{
    int r, length;
    while (cin >> length >> r)
    {
        if (C(r) > length)
            cout << "Yes" << endl;
        else {
            cout << "No" << endl;
        }
    }

}