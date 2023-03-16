#include<iostream>
#include<vector>
#include<string>

using namespace std;
class matrix{};
bool compare(const matrix& , const matrix&);
vector<int>::iterator change_val(int a, vector<int>::iterator it);
void test_6_33(vector<int> Vint, unsigned index)
{
	 unsigned sz = Vint.size();
	 if (!Vint.empty() && index < sz)
	 {
		 cout << Vint[index] << endl;
		 test_6_33(Vint, index + 1);
	}
}
bool test_6_30_subrange(const string& str1, const string& str2)
{
	auto size = (str1.size() < str2.size() ? str1.size() : str2.size());
	for (decltype(size) i = 0; i != size; i++)
	{
		if (str1[i] == str2[i])
			return true;
	}
	return false;
}
int test6_27(initializer_list<int> il)
{
	int sum = 0;
	for (auto e : il)
	{
		sum += e;
	}
	return sum;
}
int test6_21(int a, int* b)
{
	if (a > *b)
		return a;
	else
		return *b;
}
void test6_22(int* p1,int *p2)
{

	int *temp = p1;
	p1 = p2;
	p2 = temp;
}
void test6_12(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
	//与使用指针来交换相比更加简洁，而且不用拷贝指针变量的值。 
}
void test6_11_reset(int& i)
{
	i = 0;
}
void test6_10(int* p1,int* p2)
{
	int temp = *p1;
	* p1 =  *p2;
	*p2 = temp;
}
int test6_7()
{
	static  int res = -1;
	return res++;

}
int func1(int a, int b)
{
	return a + b;
}
int func2(int a, int b)
{
	return a - b;

}
int func3(int a, int b)
{
	return a * b;
}
void compute(int a, int b, int (*p)(int, int))
{
	cout << p(a, b) << endl;
}
int main()
{
	vector<decltype(func1)*> vf;
	vf.push_back(func1);
	vf.push_back(func2);
	vf.push_back(func3);
	compute(1, 3, vf[0]);
	//test_6_30_subrange("rrc", "rrr");
}
//int main(int argc,char* argv[])
//{
//	string s;
//	for (int i = 0; i < argc; i++)
//	{
//		s += argv[i];
//	}
//	
//}
/*
int main(int argc,char ** argv)
{
	
	for (int i = 0; i < argc; i++)
	{
		cout<<i<<argv[i]<<endl;
	}
	
}
*/