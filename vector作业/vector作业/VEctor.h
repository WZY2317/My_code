#pragma once

namespace bit
{
	template<class T>
	class vector {
	public:
	
		typedef T* iterator;
		typedef const T* const_iterator;
		vector() :_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{

		}
		vector(const vector<T>& v)
		{
			_start = new T[v.capacity()];
			_finish = _start + v.size();
			_endofstorage = _start + v.capacity();
			memcpy(_start, v._start, v.size() * sizeof(T));

		}
		vector(const vector<T>& v) :_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());
			swap(_start, tmp._start);
			swap(_finish, tmp._finish);
			swap(_endofstorage, tmp._endofstorage);
			

		}
		vector<T>& operator=(const vector<T>& v)
		{
			return *this;
		}
		template<class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			:_finish(nullptr)
			:_endofstorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
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
		size_t size() const
		{

			return _finish - _start;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				T* tmp = new T[n];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * size());
					delete[] _start;
				}
				_finish = tmp + size();
				_start = tmp;
				_endofstorage = _start + n;


			}

		}
		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			if (n > size())
			{
				reserve(n);
				while (_finish != _start + n)
				{
					_finish = val;
					_finish++;
				}
			}
			
		}
		void insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			assert(pos >= _start);
				if (_finish = _endofstorage)
				{
					size_t len = pos - _start;
					reserve(capacity() == 0 ? 4 : capacity() * 2);
					pos = _start + len;
				}
			iterator end = _finish;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			pos = x;
			++_finish;
			return pos;
		}
		void erase(iterator pos)
		{
			assert(pos <= _finish);
			assert(pos >= _start);
			while (pos < _finish)
			{
				*pos = *(pos + 1);
				pos++;
			}
		}
		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				size_t newCapacity = capacity() == 0 ? 4 : capacity() * 2;
				T* tmp = new T[newCapacity];
				if (_start)
				{
					memcpy(tmp, _start, sizeof(T) * size());
					delete[] _start;
				}
				
				_finish = tmp + size();
				_start = tmp;
				_endofstorage = _start + newCapacity;
				

			}
			*_finish = x;
			++_finish;
			

		}
		
		T& operator[](size_t i) const
		{
			assert(i < size());
			return	_start[i];
		}
		size_t capacity() const
		{
			return _endofstorage - _start;
		}
		/*void reserve(size_t n)
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
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}
		iterator begin();*/
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};
	void test_vector()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		//v.insert(2,2);
		for (size_t i = 0; i < v.size(); i++)
		{
			std::cout << v[i] << " ";
		}
		std::cout << std::endl;
		vector<int>::iterator it=v.begin();
		while (it != v.end())
		{
			std::cout << *it << " ";
			it++;
		}
		std::cout << std::endl;
		for (auto e : v)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;
 	}
	void test_vector1()
	{
		vector<int> v1;
		v1.push_back(0);
		v1.push_back(1);
		v1.push_back(2);
		vector<int> v2(v1);
		for (auto e : v2)
		{
			std::cout << e << " ";
		}
		std::cout << std::endl;

	}
}

