#include<iostream>
#include<vector>
#include<stack>
using namespace std;

    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        stack<int> st;
        int popi = 0, pushi = 0;
        while (pushi < pushV.size())
        {
            st.push(pushV[pushi]);
            pushi++;
            while (popi < popV.size())
            {
                if (!st.empty()&&popV[popi] == st.top())
                {
                    st.pop();
                    popi++;
                }
                else
                    break;

            }

        }
        return st.empty();


    }

int main()
{
    vector<int> v1 = { 2,1,0 };
    vector<int> v2 = { 1,2,0 };
   //Solution::IsPopOrder(v1, v2);
    IsPopOrder(v1, v2);
}