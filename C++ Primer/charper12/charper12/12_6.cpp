#include<vector>
#include<iostream>
using namespace std;
vector<int>* func1()
{
	vector<int>* pv = new  (nothrow)vector<int>;
	return pv;
}
void read_v(vector<int>* pv)
{
	int c;
	while (cin >> c)
	{
		pv->push_back(c);
	}
}
void print_ints(vector<int>* pv)
{
	for (auto e : *pv)
	{
		cout << e << endl;
	}
}
int main(int argc,char** argv)
{
	vector<int>* pv = func1();
	if (!pv)
	{
		cout << "ÄÚ´æ²»×ã" << endl;
		return -1;
	}
	read_v(pv);
	print_ints(pv);
	delete pv;
	pv = nullptr;
	return 0;

}