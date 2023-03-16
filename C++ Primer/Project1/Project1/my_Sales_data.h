#pragma once
#include<iostream>
#include<string>
class Sales_data
{
	friend std::istream& operator>>(std::istream& in, Sales_data& s);
	friend inline bool  compareIsbn(const Sales_data& s1, const Sales_data& s2);
	friend inline bool operator ==(const Sales_data& s1, const Sales_data& s2);
	friend inline bool operator !=(const Sales_data& s1, const Sales_data& s2);
public:
	Sales_data() = default;
	Sales_data(const std::string &book):bookNo(book){}
	Sales_data& operator+=(const Sales_data& );

private:
	std::string bookNo;
	unsigned int units_sold = 0;
	double sellingprice = 0.0;
	double saleprice = 0.0;
	double discount = 0.0;
	std::string isbn = 0;

};
inline bool compareIsbn(const Sales_data& s1, const Sales_data& s2)
{
	return s1.isbn == s2.isbn;
}
inline bool operator ==(const Sales_data& s1, const Sales_data& s2)
{
	return s1.bookNo == s2.bookNo && s1.discount == s2.discount && s1.isbn == s2.isbn && s1.saleprice == s2.saleprice;
}
inline bool operator !=(const Sales_data& s1, const Sales_data& s2)
{
	return !(s1==s2);
}
Sales_data& Sales_data::operator+=(const Sales_data& s)
{
	this->units_sold += s.units_sold;
	this->saleprice = (s.units_sold * s.saleprice + saleprice * units_sold) / (s.units_sold + units_sold);
	if (sellingprice != 0)
		discount = saleprice / sellingprice;
	return *this;
}
std::istream& operator>>(std::istream& in, Sales_data& s)
{
	in >> s.bookNo >> s.units_sold >> s.saleprice >> s.sellingprice;
	if (in && s.sellingprice != 0)
	{
		s.discount = s.saleprice / s.sellingprice;
	}
	else
	{
		s = Sales_data();
	}
	return in;
}
