#pragma once

class Date
{
	
	public:
		Date(int year = 1900, int month = 1, int day = 1)
			:_year(year)
			, _month(month)
			, _day(day)
		{}
	
		bool operator<(const Date& d)const
		{
			return (_year < d._year) ||
				(_year == d._year && _month < d._month) ||
				(_year == d._year && _month == d._month && _day < d._day);
		}
		bool operator>(const Date& d)const
		{
			return (_year > d._year) ||
				(_year == d._year && _month > d._month) ||
				(_year == d._year && _month == d._month && _day > d._day);
		}
private:
	int _year;
	int _month;
	int _day;
};

namespace wzy
{

	template<class T>
	struct Less
	{
		bool operator()(const T& a, const T& b) const
		{
			return a < b;
		}
	};
	template<class T>
	struct Greater
	{
		bool operator()(const T& x, const T& y) const
		{
			return x > y;
		}
	};
	template<class T, class Container = vector<T>, class compare = Less<T>>
	//template<class T, class Container = vector<T>, class compare = less<T>>
	class priority_queue
	{
	public:
		priority_queue() {}
		template<class InputIterator>
		priority_queue(InputIterator first, InputIterator last)
			:_con(first, last)
		{
			for (int i = (_con.size() - 1 - 1) / 2; i >= 0; i--)
			{
				Adjust_down(i);
			}
		}
		void Adjust_up(size_t child)
		{
			compare com;
			size_t parent = (child - 1) / 2;
			while (child > 0)
			{

				if (com(_con[parent], _con[child]))
				{
					swap(_con[parent], _con[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void Adjust_down(size_t parent)
		{
			compare com;
			//调大堆
			size_t child = (parent * 2) + 1;
			while (child < _con.size())
			{				//_con[child]<_con[child+1]
				if (child + 1 < _con.size() && com(_con[child], _con[child+1]))//这里的逻辑是不能反的，要不然就会越界了
				{
					child++;
					//先选出大的孩子，防止小的孩子交换了就不符合大堆的情况了

				}
				//_con[child] > _con[parent]
				if (com(_con[parent],_con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}
		void push(const T& x)
		{
			_con.push_back(x);
			Adjust_up(_con.size() - 1);
		}
		bool empty()
		{
			return _con.empty();
		}
		void pop()
		{
			assert(!_con.empty());
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			Adjust_down(0);
			
			



		}
		size_t size()
		{
			return _con.size();
		}
		const T& top()
		{
			return _con[0];
		}

	private:
		Container _con;
	};
	struct LessDate
	{
		bool operator()(const Date* d1, const Date* d2)const
		{
			return *d1 < *d2;
		}
	};
	void testDate()
	{
		priority_queue<Date*, vector<Date*>, LessDate> Dq;
		Dq.push(new Date(2022, 3, 16));
		Dq.push(new Date(2021, 10, 26));

	}
	void testPQueue()
	{
		priority_queue<int> pq;
		//priority_queue<int, vector<int>, greater<int>> pq;
		pq.push(3);
		pq.push(3);
		pq.push(7);
		pq.push(1);
		pq.push(9);
		while (!pq.empty())
		{
			cout << pq.top() << " ";
			pq.pop();
		}
		cout << endl;
	}


}
