#include<vector>
#include<map>
#include<iostream>
using namespace std;
template<class S>
//class UnionFindSet
//{
//public:
//	UnionFindSet(const S* a,size_t n)
//	{
//		for (int i = 0; i < n; i++)
//		{
//			_a.push_back(a[i]);
//			_indexMap[a[i]] = i;
//		}
//	}
//private:
//	vector<S> _a;
//	map<S, int> _indexMap;;
//};
class  UnionFindSet
{
public:
	UnionFindSet(size_t n)
		:ufs(n,-1)
	{

	}
	void  Union(int x1, int x2)
	{
		int root1 = Findroot(x1);
		int  root2 = Findroot(x2);
		if (root1 == root2)
			return;
		ufs[root1] += ufs[root2];
		ufs[root2] = root1;
	}
	int Findroot(int x)
	{
		int  parent = x;
		while (ufs[parent] >= 0)
		{
			parent = ufs[parent];
		}
		return  parent;	
	}
	bool InSet(int x1.int x2)
	{
		return  Findroot(x1) == Findroot(x2);
	}
	int SetSize()
	{
		int Size = 0;
		for (int e : ufs)
		{
			if (e < 0)
				size++;
		}
		return Size;
	}
private:
	vector<int> ufs;
};
int main()
{
	/*string  a[] = { "tom","jack","amy","Mike" };
	UnionFindSet<string>  ufs(a, 4);*/
}