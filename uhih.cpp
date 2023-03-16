#include<iostream>
#include<vector>
int n,m;
using namespace std;
vector<int> res;
int GYS(int n)
{
    int max=0;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            res.push_back(i);
            if(n/i!=i)
            res.push_back(n/i);
        }
            
    }
    for(int i=0;i<res.size();i++)
    {
        if(res[i]>max)
            max=res[i];
    }
    return max;
}
int main()
{
    cin>>n>>m;
    int count=0;
    while(n<=m)
    {
        n+=GYS(n);
        count++;
    }
    cout<<count<<endl;
}