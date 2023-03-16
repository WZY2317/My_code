//12.1 b1和b2指向的是同一块空间，当b1赋值给b2时，这里的指针的引用计数会递增，所以b1和b2都是四个元素

#ifndef  MY_STRBLOB_H
#define MY_STRBLOB_H
#include<vector>
#include<string>
#include<memory>
#include<initializer_list>
#include<stdexcept>
using namespace std;
class StrBlob
{
public:
	typedef vector<string>::size_type size_type;
	StrBlob();
	StrBlob(initializer_list<string> il ){}
	size_type size() const { return data->size(); }
	bool empty() { return data->empty(); }
	void push_back(const string& t)
	{
		data->push_back(t);
	}
	void pop_back()
	{
		;
	}
	string& front()
	{
		return data->front();
	}
	const string& front() const
	{

	}
	string& back()
	{
		return data->back();
	}
private:
	std::shared_ptr<vector<string>> data;
	void check(size_type i, const string& msg);
};
StrBlob::StrBlob():data(make_shared<vector<string>>()){}
//StrBlob::StrBlob(initializer_list<string> il):data(make_shared<vector<string>> (il)){}
//void StrBlob::check(size_type i, const string msg) 
//{
//	if (i >= data->size())
//		throw out_of_range(msg);
//}
//void StrBlob::pop_back()
//{
//	
//}
#endif // ! MY_STRBLOB_H
//
//12.3 常量对象不应该被允许修改vector对象的内容了
//12.4 check是私有成员的函数，只有被类里面的成员函数调用，不会被用户调用，所以比较安全
//为编写一个接收初始化列表的显式构造函数，意味着可以进行列表向类的隐式转换，在需要类的地方，可以选用列表来替代，这样使程序编写更加方便

