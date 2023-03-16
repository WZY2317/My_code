#include<iostream>
#include<vector>
#include<map>
#include<initializer_list>
#include<forward_list>
#include<assert.h>
#include <cassert>
using namespace std;
template<class T>
class Vector
{
public:
	Vector(initializer_list<T> l) :_capacity(l.size()), _size(0)
	{

	}
	Vector<T>& operator=(initializer_list<T> l)
	{
		delete[] _array;
		size_t i = 0;
		for (auto e : : l)
		{
			_array[e++];
		}
		return *this;
	}
private:
	T* _array;
	size_t _capacity;
	size_t _size;
};
class Point
{
public:
	Point(int x = 0, int y = 0) :_x(x), _y(y)
	{

	}
private:
	int _x;
	int _y;
};
void testauto()
{
	short a = 32670;
	short b = 32670;
	auto c = a + b;
	//auto���ݳ�ʼ�������Ƶ�������������


}
void testyouzhi()
{
	double x = 1.1;
	double y = 9.2;
	x + y;
	fmin(x, y);
	auto&& r1 = fmin(x, y);
	auto&& r2 = x;
	int a = 10;
	int&& n = move(a);//move�Ժ������ֵ����

}
void testflist()
{
	forward_list<int> values(10);//����ʮ��������Ԫ��

}
//��ͳ����ֵ���õ�ȱ���ǣ������ҷ���һ��ֵ�����ֵҪ�ȿ��������٣�Ч�ʲ��ߣ���ֵ����ʱ������Ĳ���ʶ��Ϊ��ֵ�Ľ���ֵ��ֱ��ת����Դ���Ӷ�Ч�ʵõ�������
//������ƶ�����
class A
{
public:
	A(int a):_a(a){}
	A() = default;
	A& operator=(const A& a);
private:
	int _a;
};
A& A::operator=(const A& a) = default;

void testdecltype()
{
	int a = 9;
	short b = 9788;
	decltype(a + b) c;
}
namespace bit
{
	class string
	{
	public:
		typedef char* iterator;
		iterator begin()
		{
			return _str;
		}

		iterator end()
		{
			return _str + _size;
		}

		string(const char* str = "")
			:_size(strlen(str))
			, _capacity(_size)
		{
			//cout << "string(char* str)" << endl;

			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		// s1.swap(s2)
		void swap(string& s)
		{
			::swap(_str, s._str);
			::swap(_size, s._size);
			::swap(_capacity, s._capacity);
		}

		// ��������
		string(const string& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(const string& s) -- ���" << endl;

			string tmp(s._str);
			swap(tmp);
		}

		// �ƶ�����
		string(string&& s)
			:_str(nullptr)
			, _size(0)
			, _capacity(0)
		{
			cout << "string(string&& s) -- ��Դת��" << endl;

			this->swap(s);
		}

		// �ƶ���ֵ
		string& operator=(string&& s)
		{
			cout << "string& operator=(string&& s) -- ת����Դ" << endl;
			swap(s);

			return *this;
		}

		string& operator=(const string& s)
		{
			cout << "string& operator=(string s) -- ���" << endl;
			string tmp(s);
			swap(tmp);

			return *this;
		}

		~string()
		{
			//cout << "~string()" << endl;

			delete[] _str;
			_str = nullptr;
		}

		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		void reserve(size_t n)
		{
			if (n > _capacity)
			{
				char* tmp = new char[n + 1];
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;

				_capacity = n;
			}
		}

		void push_back(char ch)
		{
			if (_size >= _capacity)
			{
				size_t newcapacity = _capacity == 0 ? 4 : _capacity * 2;
				reserve(newcapacity);
			}

			_str[_size] = ch;
			++_size;
			_str[_size] = '\0';
		}

		//string operator+=(char ch)
		string& operator+=(char ch)
		{
			push_back(ch);
			return *this;
		}

		string operator+(char ch)
		{
			string tmp(*this);
			push_back(ch);

			return tmp;
		}

		const char* c_str() const
		{
			return _str;
		}
	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}

int main()
{
	vector<int> v{ 1,2,3,4 };
	int* arr = new int[5]{ 1,2,3,4,5 };
	map<int, int> m{ {1,2} };
	Point p{ 0,0 };
	initializer_list<int> ili = { 1,2,3,4,5 };//���������б��ʼ��

}