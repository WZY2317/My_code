#include<iostream>
#include<fstream>
#include<vector>
#include<string>
#include<sstream>
using namespace std;
istream& func(istream& is)
{
	int word;
	auto old_state = is.rdstate();
	while ((is >> word),!is.eof())
		
	{
		if (is.bad())
		{
			throw runtime_error("IO ERROR");
		}
		if (is.fail())
		{
			cerr << "数据错误，请重试" << endl;
			is.clear();
			is.ignore(100, '\n');
			continue;
		}
		cout << word;
	}
	is.setstate(old_state);
	return is;
}
vector<string>& func8_5(string& file)
{
	
	ifstream in(file);
	if (!in)
	{
		cerr << "无法打开输入文件" << endl;
		
	}
	string line;
	vector<string> words;
	//while(in>>line)
	while (getline(in, line))
	{
		words.push_back(line);
	}
	in.close();
	vector<string>::iterator it=words.begin();
	while (it != words.end())
	{
		cout << *it << endl;
		it++;
	}

	return words;
}
bool exist(vector<vector<char>>& board, string word) {
	int row = board.size();
	int col = board[0].size();
	int beginr, beginc;
	int beginw = 0;
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (board[i][j] == word[beginw])
			{
				beginc = i;
				beginr = j;
				beginw++;

				while (beginw < word.size() && beginc < row && beginr < col)
				{
					if (beginc < col && beginr < row - 1 && board[beginr + 1][beginc] == word[beginw])
					{
						beginw++;
						beginr++;
						if (beginw == word.size())
							break;
					}
					else if (beginc < col - 1 && beginr < row && board[beginr][beginc + 1] == word[beginw])
					{
						beginw++;
						beginc++;
						if (beginw == word.size())
							break;
					}
					else
						return false;
				}
				return true;
			}
		}
	}
	return false;
}
void test8_9(string str="hhhh")
{
	ostringstream os;
	os << str;
	istringstream in(os.str());
	
}
void test8_10(void)
{
	ifstream in("data");
	if (!in)
	{
		cerr << "无法打开输入文件" << endl;
	}
	vector<string> res;
	string line;
	while (getline(cin, line))
	{
		res.push_back(line);
	}
	in.close();
	vector<string>::iterator it= res.begin();
	while (it != res.end())
	{
		istringstream is(*it);
		string word;
		while (is >> word)
		{
			cout << word << "";
		}
		it++;
	}
}
//练习8.11
//在record后面要使用clear（）
//练习8.13 cin改成istream定义的in就可以了
//练习8.14 使对象不被改变，以及不用拷贝

struct PersonInfo
{
	string name;
	vector<string> phones;
};
int main(int argc,char* argv[])
{
	/*cout << "请输入一些整数" << endl;
	func(cin);*/
	//练习8.3 遇到了文件结束符，或者IO流错误，或者读入了无效数据
	/*vector<vector<char>> board={ {'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
	exist(board, "ABCCED");*/
	/*if (argc != 3)
	{
		cerr << "请给出输入，输出文件名" << endl;
		return -1;
	}
	ifstream in(argv[1]);
	if (!in)
	{
		cerr << "无法打开输出文件" << endl;
		return -1;
	}
	ofstream out(argv[2],ofstream::app);
	if (!out)
	{
		cerr << "无法打开输入文件" << endl;
		return -1;
	}*/
	string line, word;
	vector<PersonInfo> people;
	while (getline(cin,line))
	{
		PersonInfo info;
		istringstream record(line);
		record >> info.name;
		while (record >> word)
		{
			info.phones.push_back(word);
		}
		people.push_back(info);

	}



}