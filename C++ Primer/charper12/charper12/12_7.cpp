#include<iostream>
#include<memory>
#include<vector>
#include<cstring>
using namespace std;
shared_ptr<vector<int>> new_vector()
{
	auto pv = make_shared<vector<int>>();
	return pv;
}
void read_ints(shared_ptr<vector<int>> pv)
{
	int e;
	while (cin >> e)
	{
		pv->push_back(e);
	}
}
void print_int(shared_ptr<vector<int>> pv)
{
	for (const auto& v : *pv)
	{
		cout << v << endl;
	}
}
struct desrination{};
struct connection{};
connection connect(desrination* pd)
{
	cout << "打开链接" << endl;
	return connection();
}
void disconnect(connection c)
{
	cout << "关闭链接" << endl;
}
void end_connection(connection* p)
{
	disconnect(*p);
}
void f1(desrination& d)
{
	connection c = connect(&d);
	shared_ptr<connection> p(&c, end_connection);
	//shared_ptr<connection> p(&c, [](connection* p) {disconnect(*p); }); 12.15
}
int main()
{
	const char* c1 = "hello";
	const char* c2 = "world";
	char* r = new char[strlen(c1) + strlen(c2) + 1];
	strcpy(r, c1);
	strcat(r, c2);
	delete [] r;
}
//12.8 这段程序想通过返回一个合法指针，转换为整数是一个非零值，再转换成bool 但是普通new如果开内存失败会抛异常就不会转换成bool 
// 改为new （nothrow）int就好了，还会产生一个空悬指针的问题。如果程序编写不当，会产生释放了一个指针，又去使用另外一个指针，这是一个空悬指针，已经没有空间了，就会产生错误了
//12.9 r和q指向同一块内存，但是r原本指向的一块空间没有被释放，r2和q2指向同一块内存，但是r2原来的那段空间会被释放引用计数-1，q2的引用计数+1
//12.10 这个调用是正确的，调用process，通过拷贝指针，引用计数变成2，后来销毁一份拷贝，引用计数就变成1
//12.11 get返回一个内置指针，而内置指针是不可以赋值给智能指针的
//12.12 总之就是内置指针不可以，智能指针才行
//12.13 这里的sp和p指向同一块内存，p被释放 sp就变成的空悬的智能指针
