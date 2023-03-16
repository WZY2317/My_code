#include<iostream>
using namespace std;
namespace zy {
	template<class T>
	class auto_ptr
	{
	public:
		auto_ptr(T* ptr = NULL)
			:_ptr(ptr)
		{

		}
		auto_ptr(auto_ptr<T>& ap)
			:_ptr(ap._ptr)
		{

		}
		auto_ptr<T>& operator=(auto_ptr<T>& ap)
		{
			if (ap != &this)

			{
				if (_ptr)
					delete _ptr;
				_ptr = ap._ptr;
				ap._ptr = NULL;
			}
			return *this;
		}
		~auto_ptr()
		{
			if (_ptr)
				delete _ptr;
		}
		T& operator*() { return  *_ptr; }
		T* operator->(){return _ptr;
	}
	private:
		T* _ptr;

	};
	template<class T>
	class unique_ptr
	{
		unique_ptr(T* ptr = NULL)
			:_ptr(ptr)
		{

		}
		unique_ptr(unique_ptr<T>& ap)
			:_ptr(ap._ptr)
		{

		}
		unique_ptr<T>& operator=(unique_ptr<T>& ap)
		{
			if (ap != &this)

			{
				if (_ptr)
					delete _ptr;
				_ptr = ap._ptr;
				ap._ptr = NULL;
			}
			return *this;
		}
		~unique_ptr()
		{
			if (_ptr)
				delete _ptr;
		}
		T& operator*() { return  *_ptr; }
		T* operator->() {
			return _ptr;
		}
	private:
		unique_ptr(unique_ptr<T>& ap)
			:_ptr(ap._ptr)
		{
		}
		unique_ptr<T>& operator=(unique_ptr<T>& ap) = delete;
		
		T* _ptr;
	};

}
class Date
{
public:
	Date() { cout << "Date()" << endl; }
	~Date() { cout << "~Date()" << endl; }
	int _year;
	int _month;
		int _day;
};
int main()
{
	zy::auto_ptr<Date> ap1(new Date);
	zy::auto_ptr<Date>   ap2(ap1);
	ap1->_day = 0;


}