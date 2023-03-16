#include"Sales_data.h"
inline bool compareIsbn(const Sales_item &s1, const Sales_item &s2)
{
	return s1.isbn == s2.isbn;
}
int main()
{
	Sales_item item1,item2;
	std::cin >> item1 >> item2;
	if (item1.isbn == item2.isbn)
	{
		std::cout << item1 + item2 << std::endl;
	}
	else
	{
		std::cout << "书籍要有同样的ISBN" << std::endl;
		return -1;
	}
	Sales_item total, item;
	std::cout << "请输入一共几条书籍数据" << std::endl;
	if (std::cin >> total)
	{
		std::cout << "请输入书籍数据" << std::endl;
		while (std::cin >> item)
		{
			
			if (compareIsbn(total,item))
			{
				total+=item;
			}
			else
			{
				std::cout<<"当前书籍的isbn不一样"<<std::endl;
				break;
			}
		}
		std::cout << total << std::endl;
	}
	else
	{
		std::cout << "没有数据" << std::endl;
		return -1;
	}
	Sales_item trans1,trans2;
	int num = 1;
	if (std::cin >> trans1)
	{
		while (std::cin >> trans2)
		{
			if (compareIsbn(trans1, trans2))
			{
				num++;
			}
			else
			{
				std::cout << trans1.isbn << num << "条销售记录" << std::endl;
				trans1 = trans2;
				num = 1;

			}
		}
		std::cout << trans1.isbn << num << "条销售记录" << std::endl;

	}
	else
	{
		std::cout << "没有数据" << std::endl;
		return -1;
	}


	return 0;

}