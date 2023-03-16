#include<iostream>
#include<string>
#include<vector>

using namespace std;
class Person
{
private:
	string name;
	string strAddress;
public:
	//练习7.5
	Person() = default;
	//练习7.15
	Person(const string& name, const string& strAddress)
	{
		this->name = name;
		this->strAddress = strAddress;
	}
	Person(istream& is)
	{
		is >> this->name >> this->strAddress;
	}
	string Name() const
	{
		return name;
	}
	string strAdd() const
	{
		return strAddress;
	}
	istream& is(istream& is, Person& item)
	{
		is >> item.name >> item.strAddress ;
		return is;
	}
	ostream& out(ostream& out, Person& item)
	{
		out << item.name << item.strAddress;
		return out;
	}
	//练习7/10
	//这里返回的是引用，可以作为外层read函数的实参使用
	//练习7/16：构造函数和一部分成员函数可以是共有，而数据成员和作为实现部分的函数应该跟在private后面
	//练习7/17:struct 默认成员是共有而另一个是私有
	//封装就是保护类的成员不被随意访问，通过吧类的细节设置为private 就能完成对类的封装，可以确保用户代码不会无意的破坏封装属性，还可以让类的实现细节
	//可以随时改变，而无需调整用户级别的代码
	//练习7/19：把名字和地址设置为私有，防止用户不经意的修改和破坏
	//练习7/20：确定会破坏封装，优点就是可以让非接口的函数访问类的成员

};
//class Sales_data
//{
//private:
//	string bookNo;
//	unsigned units_sold = 0;
//	double sellingprice = 0.0;//原始价格
//	double saleprice = 0.0;
//	double discount = 0.0;
//public:
//	//练习7/21
//	friend Sales_data add(const Sales_data& lhs, const Sales_data& rhs);
//	friend istream& read(istream& is, Sales_data& item);
//	friend ostream& print(ostream& os, const Sales_data& item);
//	
//	Sales_data() = default;
//	Sales_data(const string& book):bookNo(book){}
//	/*Sales_data(const string& book) :bookNo(book), units_sold(0), sellingprice(0.0), saleprice(0.0),discount(0)
//	{
//
//	}*/
//	Sales_data(const string& book, const unsigned& num, const double& sell, const double& sale)
//		:bookNo(book),units_sold(sell),sellingprice(sell),saleprice(sale)
//	{
//		if (sellingprice != 0)
//			discount = saleprice / sellingprice;
//	}
//	Sales_data(istream& is)
//	{
//		is >> this->bookNo>>this->units_sold>>this->sellingprice>>this->sellingprice;
//	}
//	string isbn() const
//	{
//		return bookNo;
//	}
//	//练习7.2
//	Sales_data& combine(const Sales_data& rhs)
//	{
//		units_sold += rhs.units_sold;
//		saleprice = (saleprice * discount + rhs.saleprice * rhs.discount);
//		if (sellingprice != 0)
//		{
//			discount = sellingprice / saleprice;
//		}
//		return *this;
//	}
//	//类的成员函数默认是内联的
//	double avg_price() const
//	{
//	
//	}
//	
//	//print(cout,trans);
//
//	//练习7.8：因为需要从标准输入读取数据写入到sales_data 因此要有修改对象的权限
//	
//};
//Sales_data add(const Sales_data& lhs, const Sales_data& rhs)
//{
//	Sales_data sum = lhs;
//	sum.combine(rhs);
//	return sum;
//}
////练习7.6
//istream& read(istream& is, Sales_data& item)
//{
//	is >> item.bookNo >> item.units_sold >> item.sellingprice >> item.saleprice;
//	return is;
//}
////read(cin,trans);
//ostream& print(ostream& os, const Sales_data& item)
//{
//	os << item.bookNo << item.units_sold << item.sellingprice << item.saleprice;
//	return os;
//}

class Window_mgr
{
public:
	void clear();
};
class Screen
{
	//练习7.32
	friend void Window_mgr::clear();

private:
	typedef string::size_type pos;
	unsigned height = 0,width = 0;
	unsigned cursor = 0;
	string contents;
	void do_display(ostream& os) const
	{
		os << contents;
		
	}
public:
	
	Screen() = default;
	Screen(unsigned ht, unsigned wh) :height(ht), width(wh), contents(ht* wh, ' ')
	{
		
	}
	Screen(unsigned ht, unsigned wd, char c) :height(ht), width(wd), contents(ht* wd, 'c')
	{

	}
	//练习7/25 他的四个数据成员都是内置类型，因此直接使用类对象执行拷贝和赋值操作是可以的
	Screen& move(pos r, pos c)
	{
		pos row = r * width;
		cursor = row + c;
		return *this;
	}
	Screen& set(char ch)
	{
		contents[cursor] = ch;
		return *this;
	}
	Screen& display(ostream& os)
	{
		do_display(os);
		return *this;
	}
	const Screen& display(ostream& os) const
	{
		do_display(os);
		return *this;
	}
	pos size() const
	{

	}


};

//练习7.33
//Screen::pos Screen::size() const
//{
//	return height * width;
//}
//练习7.34 编译会出错，因为上面使用过的pos ，根本不知道 
//练习7.35 Type 使用的是类内部的， parm也是类的内部的， setval的返回值和声明对应不上， Type前面应该加上 Exercise：：
//练习7.36，成员初始化的顺序是和定义的顺序一样
//练习7.37，第一个是调用默认构造函数，第二个是调用const string&
//练习7.38，Sales_data(istream &is=cin){is>>*this;
//练习7.39，提供了默认构造函数之后，当我们不用任何参数定义一个对象的时候，就不知道调用哪一个默认构造函数好，这样就会引起二义性。
//练习7.40，7.41，7.42略




void Window_mgr::clear()
{
	Screen myScreen(10, 10, 'X');
	myScreen.contents=" ";
}
class X;
class Y;
class X
{
	Y* x;
};
class Y
{
	X y;
};
//练习7.43
class NoDefault
{
public:
	NoDefault(int i)
	{

	}
private:
	int val;
};
class C
{
	C(int i = 0) :c(i)
	{

	}
private:
	NoDefault c;
};
//练习7.44 7.45 Nodefault没有默认构造函数， C有默认构造函数所以不会报错
//练习7.46 如果没有构造函数，就会使用默认的合成构造函数，如果某个构造函数包含若干形参，但是同时为这些形参提供默认实参，这样也是默认构造函数
//每一个类都要构建一个默认构造函数 对于编译器合成的默认构造函数，如果成员中有类，那么就把这些类执行各自所属的构造函数，内置类型和复合类型的成员
//只对定义在全局作用域的对象执行初始化
string reverseWords(string s) {
	vector<string> vs;
	for (int i = 0; i < s.size(); i++)
	{
		string tmp;
		while (s[i] != ' ' && i < s.size())
		{
			tmp += s[i];
			i++;
		}
		
		vs.push_back(tmp);
	}
	

	string res;
	for (auto it = vs.rbegin(); it != vs.rend(); it++)
	{
		res = res + *it + ' ';
	}
	return res.substr(0, res.size() - 1);
}
//练习 7.58
class Account
{
private:
	string strName;
	double aAmount = 0.0;
	static double dRate;
};
//练习7.59 除了静态常量成员之外，其他静态成员不能在类内初始化
int main()
{
	//explicit 用于抑制类类型的饮食转换
	//练习7.52 略
	//7.53略 7.54：constexpr函数只能有返回语句，但是set-函数是设置数据成员的值 7.55 聚合类都是字面值常量
	//7.56 静态成员指的是前面带有static 的类的成员，它不属于任何一个对象，而是属于所有类所共有的，
	//优点：作用域位于类的范围之内，避免与其他类的成员或全局作用域的名字冲突，可以是私有成员，但是全局变量就不可以，而且静态成员可以作为默认实参
	




}