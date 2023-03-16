#pragma once
#include<vector>
#include<list>
#include<forward_list>


// 适配器模式
namespace bit
{
	// stack<int, vector<int>> s;
	// stack<int, list<int>> s;

	template<class T, class Container = deque<T>>
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

		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_back();
		}
	private:
		//vector<T> _v;
		Container _con;
	};

	void test_stack()
	{
		// 后进先出 -- 不支持迭代器
		//stack<int, std::vector<int>> s;
		//stack<int, std::list<int>> s;
		stack<int> s;

		//stack<int, std::forward_list<int>> s;
		//stack<int, string> s;
		//stack<string, string> st;
		//st.push("11111");

		s.push(1);
		s.push(2);
		s.push(3);
		s.push(400);

		while (!s.empty())
		{
			cout << s.top() << " ";
			s.pop();
		}
		cout << endl;
	}
}
