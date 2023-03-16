#include<iostream>
#include<string.h>
using namespace std;
void Teststring1()
{
	string s("hello string!!");
	cout << s.size() << endl;
	cout << s.length() << endl;
	cout << s.capacity() << endl;//总空间大小
	cout << s << endl;
	s.clear();
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.resize(10, 'a');
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.resize(5);//清空时将size清0，底层空间不变
	cout << s.capacity()<<endl;
	s.resize(15);
	cout << s.size() << endl;
	cout << s.capacity()<<endl;
	cout << s << endl;
	//将s中有效字符串缩小到五个
	s.resize(5);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	cout << s << endl;

}
void Teststring2()
{
	string s;
	s.reserve(100);
	cout << s.size() << endl;
	cout << s.capacity() << endl;
	s.reserve(50);
	cout << s.size() << endl;
	cout << s.capacity() << endl;

}
void TestPushBack()
{
	string s;
	size_t sz = s.capacity();
	cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity changed:" << sz << '\n';
		}
	}

}
void TestPushBackReserve()
{
	string s;
	s.reserve(100);
	size_t sz = s.capacity();

	cout << "making s grow:\n";
	//cout << "making s grow:\n";
	for (int i = 0; i < 100; ++i)
	{
		s.push_back('c');
		if (sz != s.capacity())
		{
			sz = s.capacity();
			cout << "capacity:" << sz << '\n';
		}
	}
}
void  Teststringp()
{
	string s1("hello String!!");
	const string s2("Hello string!!");
	cout << s1 << " " << s2 << endl;
	s1[0] = 'H';
	cout << s1 << endl;
	//s2[0] = 'k';const类型对象不能修改

}
void Teststringl()
{
	string s("hello jf");
	//三种遍历方式
	for (size_t i = 0; i < s.size(); ++i)
	{
		cout << s[i] << endl;
	}
	string::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << endl;
		++it;
	}
	string::reverse_iterator rit = s.rbegin();
	while (rit != s.rend())
	{
		cout << *rit << endl;
	}
	//范围for
	for (auto ch : s)
	{
		cout << ch << endl;
	}
}
void Teststringm()
{
	string str;
	str.push_back(' ');
	str.append("hello");
	str += 'b';
	str += "it";
	cout << str << endl;
	cout << str.c_str() << endl;//以C语言的方式打印字符串
	//获取file的后缀
	string file1("string.cpp");
	size_t pos = file1.rfind('.');
	string suffix(file1.substr(pos, file1.size() - pos));
	cout << suffix << endl;
}
int main()
{
	//Teststring2();
	//TestPushBackReserve();
	Teststringm();
}