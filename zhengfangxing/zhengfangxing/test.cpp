#include<iostream>
int n, m;
int main()
{
	std::cin >> n >> m;
	int Num_sq=0;
	int Num_tri=0;
	//int x = (n > m) ? m : n;

	for (int i = 0; i < n; i++)
	
		for (int j = 0; j < m; j++)
		{
			if (i == j)
			{
				Num_sq += (n - i) * (m - j);
			}
			else
				Num_tri += (n - i) * (m - j);
		}
	
	
	std::cout << Num_sq <<" " << Num_tri;

}