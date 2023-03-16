#include<iostream>
#include<vector>
using namespace std;
void shuffle(vector<int>& card, int n, int k)
{
	while (k--)
	{
		vector<int> temp(card.begin(), card.end());
		for (int i = 0; i < n; i++)
		{
			card[2 * i] = temp[i];
			card[2 * i + 1] = temp[i + n];
		}
	}
}
int main()
{
	int groupNum;
	
	cin >> groupNum;
	while (groupNum--)
	{
		int n; int k;
		cin >> n >> k;
		vector<int> card;
		card.resize(2 * n, 0);
		for (int i = 0; i < 2 * n; i++)
		{
			cin >> card[i];
		}
		shuffle(card, n, k);
		for (int i = 0; i < 2 * n; i++)
		{
			if (i == 2 * n - 1)
				cout << card[i] << endl;
			else
				cout << card[i] << endl;
		}
	}
}

//int main()
//{
//	int groupNum=0;
//	int n=0;
//	int k=0;
//	vector<int> V;
//	V.push_back(0);
//	vector<int> V0;
//	V0.push_back(0);
//	cin >> groupNum;
//	int temp;
//	while (groupNum--)
//	{
//		cin >> n >> k;
//		for (int i = 1; i <= 2 * n; i++)
//		{
//			cin >> temp;
//			V.push_back(temp);
//		}
//		for (int i = n + 1; i <= 2 * n; i++)
//		{
//			V0.push_back(V[i - n]) ;
//		}
//		while (k--)
//		{
//			int pos = n ;
//			while (n)
//			{
//				
//				V0.insert(V0.end(), V[n--]);
//				pos -= 2;
//			}
//			for (int i = n + 1; i <= 2 * n; i++)
//			{
//				V[i - n] = V0[i];
//			}
//		}
//		for (int i = 1; i <= V0.size(); i++)
//		{
//			cout << V0[i] << endl;
//		}
//	}
//	return 0;
//}