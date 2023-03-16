#include<vector>
#include<string>
#include<map>
#include<set>
#include<fstream>
#include<sstream>
#include <iostream>
using namespace std;
class TextQuery
{
	
public:
	typedef string::size_type line_no;
	TextQuery(ifstream& is) 
	{
		string text;
		while (getline(is, text))
		{
			file.push_back(text);
			int n = file.size() - 1;
			istringstream line(text);
			string word;
			while (line >> word)
			{
				wordNumber[cleanup_str(word)].insert(n);
			}
			
		}
	}
	string cleanup_str(const string& word)
	{
		string ret;
		for (auto it = word.begin(); it != word.end(); it++)
		{
			if (!ispunct(*it))
				ret += tolower(*it);
			//如果不是空格
		}
		return ret;
	}
	ostream& Query_and_print(const string& sought, ostream& os)
	{
		auto loc = wordNumber.find(sought);
		if (loc == wordNumber.end())
		{

		}
		else
		{
			auto lines = loc->second;
			os << sought << "occurs" << lines.size() << "次" << endl;
			for (auto num : lines)
			{
				os << "\t第" << num + 1 << "行" << *(file.begin() + num) << endl;
			}
		}
		return os;
	}
	void runQueries(ifstream& infile)
	{
		TextQuery input(infile);
		while (true)
		{
			cout << "enter a word to look for" << endl;
			string find;
			if ((!cin >> find) || find == "q")
				break;
			Query_and_print(find, cout);
		}
	}

private:
	vector<string> file;
	map<string, set<line_no>> wordNumber;
};
//12.31 用vector更好，虽然set可以让行号是有序的，但是本来读入的行号就是有序的，所以不需要用set ，set的底层是红黑树，插入的是logn，还是vector更快
