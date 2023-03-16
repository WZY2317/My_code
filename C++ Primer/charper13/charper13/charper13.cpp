#include<string>
#include<iostream>
#include<vector>
using namespace std;
//13.1 当一个构造函数的参数是自身对象的引用，而且其他参数都有默认值的话，这个函数就是拷贝构造函数
//拷贝初始化， （=） 将一个对象作为实参，传递给一个非引用的形参的时候也会用到，以及一个函数的返回类型不是引用的话，也会调用拷贝构造函数
//13.2 拷贝构造函数的参数必须传递引用，因为如果不传引用的话，在传递给形参的时候会调用拷贝构造函数，然后就会一直调用拷贝构造函数
//13.3对于合成的拷贝构造函数要逐个拷贝非const成员，对于内置类型的成员，直接进行内存拷贝，对于类，要调用其拷贝构造函数
//13.4 = 会用到拷贝构造函数，而且初始化一个point数组的时候也用到了，不仅如此这里返回一个非引用类型的类也用到了

//13.6拷贝赋值运算符是用来实现拷贝赋值的，左侧运算对象绑定到隐含的this指针上面，右侧运算对象绑定在所属类类型上，当对类对象进行赋值是，会使用拷贝赋值运算符
//通常情况下，合成的拷贝构造函数会把不是static的成员逐个赋值给左侧对象的成员，//如果一个类没有自己的拷贝赋值运算符，那么就会调用编译器默认生成的
//13.7 会把成员data赋值给左侧的运算符，而且这里的sharedptr的引用计数加一
//13.9 析构函数就是用来释放对象所使用的资源，销毁非静态数据的，如果一个类没有显式的定义一个析构函数，那么编译器会自动分配一个合成的构造函数，
//这个合成的构造函数并非什么都不做，当空函数提执行完后，非静态成员会被逐个销毁。也就是析构函数体之后隐含的析构阶段中进行销毁的
// 
//13.10 调用合成的析构函数，data被销毁，智能指针引用计数会-1 ，指向的对象也会被销毁 
//13.11 这里面一共四个参数 类的对象或者参数在函数调用结束之后都会调用析构函数，但是里面有一个指针类型的，这样的只有指向的对象被析构，这个指针才会消失
//13.15 这里的序号都是重复的，合成拷贝构造函数被调用，而合成拷贝构造函数会直接复制成员，
//13.16 自己定义了拷贝构造函数之后，会生成新的序号，但是这里的参数传递是值传递，注意在值传递的过程中，会调用拷贝构造函数，所以是01234
//13.17 当采用引用传递的时候就会是正常结果
//13,19 需要，如果不定义自己的拷贝构造函数，对于复制时，会调用合成的拷贝复制函数，这样的话，编号就不是唯一的了，序号就变得相同了
//13.20 略
//13.45 右值引用绑定到一个即将被销毁的值上去，左值引用就是给一个变量起别名，也就是常规引用，左值具有持久的状态，而右值是短暂的
//13.46 r1是右值引用，因为函数返回的是一个右值 r2是左值引用，因为下标运算返回的是左值 r3 是左值，因为r1是一个变量，而变量是左值 r4 是右值引用


class Hasptr
{
public:
	~Hasptr() {
		delete ps;
	}
	Hasptr(const std::string& s = std::string()) :ps(new std::string(s)), i(0)
	{

	}
	Hasptr(const Hasptr& ha)
	{
		ps = new std::string(*ha.ps);
		i = ha.i;
	}
	Hasptr& operator=(const Hasptr& ha)
	{
		auto news = new std::string(*ha.ps);
		delete ps;
		ps = news;
		i = ha.i;
		return *this;
	}
	string& operator*()
	{
		return *ps;
	}
private:
	std::string* ps;
	int i;
};
struct X
{
	X() { std::cout << "构造函数X" << std::endl; }
	X(const X&) {
		std::cout << "拷贝构造函数" << std::endl;

	}
	X& operator=(const X& rhs)
	{
		std::cout << "拷贝赋值运算符=（const X&）" <<std:: endl;
		return *this;
	}
	~X() { std::cout << "析构函数" << std::endl; }
};
class numbered
{
private:
	static int seq;
public:
	numbered() { mysn = seq++; }
	numbered(numbered& n) { mysn = seq++; }

	int mysn;
};
void f(numbered& s)
{
	cout << s.mysn << endl;
}
void f1(X x)
{

}
void f2(X& x)
{

}
class Employee
{
	
public:
	Employee() { mysn = number++; }
	Employee(const string& nam)
	{
		name = nam;
		mysn = number++;
	}
	Employee(Employee& e)
	{
		name = e.name;
		mysn = number++;
	}
	Employee& operator=(Employee& rhs)
	{
		name = rhs.name;
		return *this;
	}
	const string& getname()
	{
		return this->name;
	}

private:
	string  name;
	static int number;
	int mysn;
};
int main()
{
	X x;
	cout << endl;
	cout << "非引用参数传递" << endl;
	f1(x);
	cout << endl;
	cout << "引用参数传递" << endl;
	f2(x);
	cout << endl;
	cout << "动态分配" << endl;
	X* px = new X;
	cout << endl;
	cout << "添加到容器中" << endl;
	vector<X> vx;
	vx.push_back(x);
	cout << endl;
	cout << "释放动态分配对象" << endl;
	delete px;
	cout << endl;
	cout << "间接初始化和赋值" << endl;
	X y = x;
	y = x; cout << endl;
	
	
}