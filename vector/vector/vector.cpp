#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <assert.h>
using namespace std;

#include "vector.h"

void test_vector1()
{
	vector<int> v1;
	vector<int> v2(10, 8);
	vector<int> v3(++v2.begin(), --v2.end());
	vector<int> v4(v3);

	string s("hello world");
	vector<char> v5(s.begin(), s.end());
}

void test_vector2()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	// ����
	for (size_t i = 0; i < v.size(); ++i)
	{
		v[i] += 1;
		cout << v[i] << " ";
	}
	cout << endl;

	// 
	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		*it -= 1;
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	//int a[] = { 1, 2, 3 };
	//// ԭ��ָ�������Ȼ�ĵ�����������֧�ַ�Χfor���ᱻ�滻ָ��
	//for (int* p = a; p < a + sizeof(a) / sizeof(int); ++p)
	//{}
}

void test_vector3()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	cout << v.max_size() << endl;

	v.reserve(100);   // ����
	v.resize(100, 5); // ����+��ʼ��  ��  ɾ������
	v.resize(2);

	//v[3];
	//v.at(3);
}

void test_vector4()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);

	//v.assign(10, 5);
	vector<int>::iterator ret = find(v.begin(), v.end(), 3);
	if (ret != v.end())
	{
		cout << "�ҵ���" << endl;
		v.insert(ret, 30);
		//v.erase(ret); // ��������ɾ����ΪretʧЧ�ˡ����������ʧЧ���⣬���Ǻ����ϸ��
	}

	v.insert(v.begin(), -1);

	//vector<int>::iterator pos = find(v.begin(), v.end(), 300);
	/*vector<int>::iterator pos = find(v.begin(), v.end(), 300);
	if (pos != v.end())
	{
		v.erase(pos);
	}*/

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	v.clear();

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

//int main()
//{
//	test_vector4();
//
//	return 0;
//}

#include <iostream>
#include <vector>

//int main()
//{
//	size_t sz;
//	std::vector<int> foo;
//	sz = foo.capacity();
//	std::cout << "making foo grow:\n";
//	for (int i = 0; i < 100; ++i) {
//		foo.push_back(i);
//		if (sz != foo.capacity()) {
//			sz = foo.capacity();
//			std::cout << "capacity changed: " << sz << '\n';
//		}
//	}
//}

//int main()
//{
//	vector<vector<int>> vv;
//	vv.resize(5);
//
//	for (size_t i = 0; i < 5; ++i)
//	{
//		vv[i].resize(i + 1);
//		//vv[i][0] = vv[i][vv[i].size() - 1] = 1;
//		vv[i].front() = vv[i].back() = 1;
//	}
//
//	int j = int();
//	int k = int(10);
//
//
//	return 0;
//}

int main()
{
	//bit::test_vector1();
	bit::test_vector2();

	return 0;
}