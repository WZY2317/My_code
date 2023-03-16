#include<iostream>
#include<typeinfo>
//2.39
struct Sales_data {
	std::string bookNo;
	unsigned int units_sold = 0;
	double sellingprice = 0.0;
	double saleprice = 0.0;
	double discount = 0.0;
};
int main()
{
	return 0;
}
//int main()
//{
//	//2.35
//	const int i = 42;
//	auto j = i;
//	const auto& k = i;
//	auto* p = &i;
//	const auto j2 = i, &k2 = i;
//	std::cout << typeid(i).name() << std::endl;
//	std::cout << typeid(j).name() << std::endl;
//	std::cout << typeid(k).name() << std::endl;
//	std::cout << typeid(p).name() << std::endl;
//	std::cout << typeid(j2).name() << std::endl;
//	std::cout << typeid(k2).name() << std::endl;
//	std::cout << typeid(i).name() << std::endl;
//}
//int main()
//{
//	//2.1
//	std::cout << "2\x4d\012";
//	std::cout << "2\tM\n";
//	return 0;
//	//\x4d 表示M \012 表示换行 \n表示换行
//}