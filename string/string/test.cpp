#include<iostream>
using namespace std;
void Teststring1()
{
	string s("hello string!!");
	cout << s.size() << endl;
	cout << s.length << endl;
	cout << s.capacity << endl;
	cout << s << endl;
}
int main()
{
	Teststring1();
}