#pragma once
#include<vector>
#include<list>
#include<forward_list>
#include<deque>
#include<string>
using namespace std;
namespace ww
{
	template<class T,class Container=deque<T>>
	class stack
	{
	public:
		bool empty() const
		{
			return _con.empty();
		}
		size_t size() const
		{
			return _con.size();
		}
		const T& top() const
		{
			return _con.back();
		}
		void push()
		{
			_con.push_back();

		}
		void pop()
		{
			_con.pop();
		}
	private:
		Container _con;
	};
	
}
void test_stack()
{
	//stack<int, std::vector<int>> s;
	//stack<int, std::list<int>> s;
	stack<int, vector<int>> s;
	s.push(1);
	s.push(2);
	s.push(3);
	while (!s.empty())
	{
		cout << s.top() << " ";
		s.pop();
	}
	cout << endl;
}

