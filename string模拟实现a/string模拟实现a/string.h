#pragma once
class string

{

public:

	string(const char* str )
		:_str(new char[strlen(str)+1])
	{
		strcpy(_str, str);
	}

	string(const string& s)
		:_str(nullptr)
	{
		string tmp(s._str);
		swap(_str, tmp._str);
	}

		string& operator=( string& s)
		{
			wap(_str, s._str);
			return *this;

		}

	~string()
	{
		if (_str)
		{
			delete[] _str;
			_str = nullptr;
		}
	}

private:

	char* _str;

};
void test()
{
	string s1("hello world");
		string s2(s1);
	
			string s3("sort");
		s1 = s3;
		s3 = s3;
}

