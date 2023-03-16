#pragma once
namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}
		/*vector(const vector<T>& v)
		{
			_start = new T[v.capacity()];
			_finish = _start + v.size();
			_endofstorage = _start + v.capacity();
			memccpy(_start, v._start, v.size() * sizeof(T));
		}*///tradition
		vector(const vector<T>& v)
		{

		}
		vector<T> operator=(const vector<int>& v)
		{
			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}
		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const T& operator[](size_t i) const
		{
			assert(i < size());
			return _start[i];
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * size());
					delete[] _start;
				}

				_start = tmp;
				// _finish = _start + size(); size
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}

		void resize(size_t n, const T& val = T())//const 延长匿名对象的生命周期，出了函数作用域再调析构函数
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}

				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		void insert(iterator pos, const T& x);
		void erase(iterator pos);

		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				// 
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);

		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	class Solution {
	public:
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> vv;
			vv.resize(numRows);
			for (size_t i = 0; i < numRows; ++i)
			{
				vv[i].resize(i + 1);
				vv[i][0] = vv[i][vv[i].size() - 1] = 1;
			}

			for (size_t i = 0; i < vv.size(); ++i)
			{
				for (size_t j = 0; j < vv[i].size(); ++j)
				{
					if (vv[i][j] == 0)
					{
						vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
					}
				}
			}

			return vv;
		}
	};

	class A
	{
	public:
		~A()
		{
			cout << "~A()" << endl;
		}
	};

	void test_vector2()
	{
		vector<vector<int>> vv = Solution().generate(5);
		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; j < vv[i].size(); ++j)
			{
				cout << vv[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		A();
		const A& x = A();

		string("hello");
		const string& s = string("hello111111111111111111111111111111111111");

		int i = 0;
	}
	void test_vector3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		vector<int> v2(v1);
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}