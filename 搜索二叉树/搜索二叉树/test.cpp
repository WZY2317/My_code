#include<iostream>
using namespace std;
#include"BinarySearchTree.h"

void test()
{
	BSTree<int> t;
	int a[] = { 5,3,4,1,7,8,2,6,0,9 };
	for (auto e : a)
	{
		t.Insert(e);
	}
	t.InOrder();
	t.Erase(7);
	t.InOrder();
	t.Erase(5);
	t.InOrder();

}
int main()
{
	test();
}