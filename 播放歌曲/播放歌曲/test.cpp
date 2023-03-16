#include<iostream>
#include<vector>
#include<stack>
using namespace std;



int main()
{
	int n;
	cin >> n;
	vector<int> V;
	string VS;
	cin >>VS;

	stack<int> S;
	int i = 1;
	
	
	
		while (i <= n)
		{
			V.push_back(i++);
		}
		
		int index = 0;
		
		
		for (int it =0; it <= VS.size(); it++)
		{
			if (VS[it] == 'U')
			{
				if (index == 0)
				{
					index = V.size()-1;
					S.push(V[index]);
				}
				else
				{
					index--;
					S.push(V[index]);
				
				}
			}
			if (VS[it] == 'D')
			{
				if (index == V.size()-1)
				{
					index = 0;
					S.push(V[0]);
				}
				else
				{
					index++;
					S.push(V[index]);
				}

			}
		}

	
	int top = S.top();
	while (!S.empty())
	{
		cout << S.top() << " ";
		S.pop();
	}
	cout << endl;
	cout << top << endl;

}