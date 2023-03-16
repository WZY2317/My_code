#include<vector>
#include<list>
#include<string>
#include<iostream>
#include<deque>
using namespace std;
//9.1  1.list适用随机插入 2.适用于头部和尾部的操作是deque vector不能头插3.快排设计很多随机的访问 list就不好了，要用vector
//9.2  vector<deque<int>>
//9.3 begin-end 之间 
bool Train9_4(vector<int>::iterator it1, vector<int>::iterator it2, int val)
{
	while (it1 != it2)
	{
		if (*it1 == val)
			return true;
		else
			it1++;
	}
	return false;
}
vector<int>::iterator Train9_5(vector<int>::iterator it1, vector<int>::iterator it2, int val)
{
	while (it1 != it2)
	{
		if (*it1 == val)
			return it1;
		else
			it1++;
	}
	return it2;
}
void Train9_20(deque<int>& que0, deque<int>& que1, list<int>& st)
{
	for (int e : st)
	{
		if (e % 2 == 1)
			que0.push_back(e);
		else
			que1.push_back(e);
	}
}
//9.6 begin不可能到达end的位置 9.7 vector<int>::iterator 9.8 list<string>::iterator  如果是写入 要用引用 也就是 list<string>::reference
//9.9 普通迭代器 和const迭代器 当不需要写访问时，使用const迭代器 9.10略
//9.11 略 9.12  接收一个已有容器的构造函数，会继承所有的数据和类型，但是当我们不想要全部的元素的时候就可以使用接收两个迭代器的构造函数
void Train9_22()
{
	vector<int> iv = { 1,2,3,3,4 };
	int some_val = 1;
	vector<int>::iterator iter = iv.begin();
	int org_size = iv.size(), new_ele = 0;
	while (iter != (iv.begin() + org_size / 2 + new_ele))
	{
		if (*iter == some_val)
		{
			iter = iv.insert(iter, 2 * some_val);
			new_ele++;
			iter++;
			iter++;
		}
		else
			iter++;
	}
}
void Train9_31()
{
	list<int> li = { 0,1,2,3,4,5,6,7,8,9 };
	auto iter = li.begin();
	while (iter != li.end())
	{
		if (*iter % 2)
		{
			iter = li.insert(iter, *iter);
			iter++;
			iter++;
		}
		else
		{
			iter = li.erase(iter);
		}
	}
}
void replace_string(string& s, const string& oldval, const string& newval)//9.43
{
	int oldsize = oldval.size();
	if (oldsize == 0)
		return;
	auto iter = s.begin();
	while (iter != s.end())
	{
		auto iter1 = iter;
		auto iter2 = oldval.begin();
		while (iter2 != oldval.end() && *iter1 == *iter2)
		{
			iter1++;
			iter2++;
		}
		if (iter2 == oldval.end())
		{
			iter = s.erase(iter, iter1);
			if (newval.size())
			{
				iter2 = newval.end();
				while (iter2 > newval.begin())
				{
					iter2--;
					iter = s.insert(iter, *iter2);
				}
			}
			iter2 += newval.size();
		}
		else
			iter++;
	}
 }
void replace_stringp(string& s, const string& oldval, const string& newval)//9.44
{
	int p = 0;
	while ((p = s.find(oldval, p)) != string::npos)
	{
		s.replace(p, oldval.size(), newval);
		p += newval.size();
	}
}
void Train9_47()
{
	string s = "ab2c3d7R4E6";
	string number = "0123456789";
	string::size_type pos = 0;
	while ((pos = s.find_first_not_of(number, pos))!=string::npos)
	{
		cout << s[pos] << endl;
		pos++;
	}
}
//9.48 9.49 略
//9.50 使用stoi函数即可 stof
class date
{
private:
	unsigned year;
	unsigned month;
	unsigned day;
public:
	date() = default;
	date(const string& ){}
};
int main()
{
	//9.14
	/*list<char*> ilist = {"ab","bb","cb","!"};
	vector<string> ivec(ilist.begin(), ilist.end());*/
	//9.15 可以用==  9.16 略 9.17 第一容器类型要一样，第二类里面要重载了<的运算符
	//9.18 
	string in;
	deque<string> ddeque;
	while (cin >> in)
	{
		ddeque.push_back(in);
	}
	for (auto e : ddeque)
	{
		cout << e << endl;
	}
	//9.19 略
	//9.22 这段代码错误是因为insert操作导致的迭代器失效
	//iter会失效，mid也会失效
	// 9.24
	vector<int> iv;
	cout << iv.at(0) << endl;
	cout << iv[0] << endl;
	cout << *iv.begin() << endl;
	cout << iv.front() << endl;
	//9.25  两个迭代器相等的情况下什么也不会发生，如果是尾后迭代器也同样什么都不会发生 9.26略	
	//9.29 会在末尾添加75个元素，并且值初始化， 会删除90个元素 9.30 必须提供一个默认构造函数
	//9.31 list 和forward-list 不支持迭代器的加减，原因是因为list的存储空间不是连续的，应该多次调用++来实现
	//9.32 不合法 参数传递是从右向左，*iter++传递之后，iter的位置就变了 第一个参数的位置就不是应该传递的位置了
	//9.33 向vector中插入元素时，容器中所有的迭代器会失效，如果没有这个赋值，begin会失效
	//9.35 size是实际的空间，capacity 是预留的空间 9.36 不可能 9.37 list 的是动态分配的，array是固定的  9.38 略
	//9.39 先是分配 1024 个空间，后来插入了一部分元素，再后来分配了当前size的一个半的空间，而且后面的空间是空串
	//9.40 256 1.5*256  1000 1024*2 1028 -1024*2 resize 的空间如果超过 给定的空间，会引起空间的再次分配
	//9.41 用迭代器去初始化就可以了
	//9.42 要先用reverse来初始化


}