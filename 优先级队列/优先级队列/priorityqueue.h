#pragma once


namespace bit
{
	template<class T,class Container=vector<T>,class compare=less<T>>
	class priority_queue
	{
	public:
		priority_queue(){}
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

				if (com(_con[parent]), _con[child]))
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
			//调大堆
			size_t child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (_con[child + 1] > _con[child] && child + 1 < _con.size())
				{
					child++;
				//先选出大的孩子，防止小的孩子交换了就不符合大堆的情况了

				}
				if (_con[child] > _con[parent])
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
			std::cout << pq.top() << " ";
			pq.pop();
		}
		std::cout << std::endl;
	}

}
