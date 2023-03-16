#include<iostream>
#include<string>
#include<vector>
using namespace std;
class A
{
public:
	virtual void f(){}
};
class B :public A
{

};
void fun(A* pa)
{
	B* pb1 = static_cast<B*>(pa);
	B* pb2 = dynamic_cast<B*>(pa);
	cout << "pb1:" << pb1 << endl;
	cout << "pb2:" << pb2 << endl;
}

void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> res;
    int index1 = 0;
    int index2 = 0;
    while (index1 < m || index2 < n)
    {
        if (nums1[index1] < nums2[index2]&&index1<m)
        {
            res.push_back(nums1[index1]);
            index1++;
        }
        else
        {
            res.push_back(nums2[index2]);
            index2++;
        }
        
    }
    for (int i = 0; i < res.size(); i++)
    {
        nums1[i] = res[i];
    }

}
int  main()
{
	//double d = 13.14;
	//std::string a = reinterpret_cast<std::string>(d);
	//int a = static_cast<int>(d);
	//std::cout << a << std::endl;
	/*const int a = 2;
	int* p = const_cast<int*>(&a);
	*p = 3;
	cout << *p << endl;*/
	/*A a;
	B  b;
	fun(&a);
	fun(&b);
	return 0;*/
    vector<int> nums1 = { 1,2,3,0,0,0 };
    vector<int> nums2 = { 2,5,6 };
    merge(nums1, 3, nums2, 3);
	
}