#include<iostream>
#include <fstream>
#include <sstream>
#include<string>
#include<assert.h>
#pragma warning(disable : 4996)
#define _CTR_SECURE_NO_WARNINGS	1			
using namespace std;

class Date
{

	friend ofstream& operator<<(ofstream& ofs, Date& d);
	friend ostringstream& operator<<(ostringstream& oss, Date& d);
public:
	Date(int year=2022, int month=1, int day=1)
		:_year(year)
		, _month(month)
		, _day(day)
	{

	}
	
private:
	int _year;
	int _month;
	int _day;
};
ofstream& operator<<(ofstream& ofs, Date& d)
{
	ofs << d._year << " " << d._month << " " << d._day << endl;

	return ofs;
}
ostringstream& operator<<(ostringstream& oss, Date& d)
{
	oss << d._year << " " << d._month << " " << d._day << endl;
	return oss;
}
struct ServerInfo
{
	char _ip[32];
	int _port;
	Date _d;
};
void Test_W_Bin()
{
	ServerInfo info = { "127.0.0.1",80 };
	FILE* fout = fopen("test.bin", "w");
	assert(fout);
	fwrite(fout, sizeof(info), 1, fout);
	fclose(fout);


}
void TestC_R_Bin()
{
	FILE* fin = fopen("test.bin", "r");
	assert(fin);
	ServerInfo info;
	fread(&info, sizeof(info), 1, fin);

	fclose(fin);
	printf("%s:%d\n", info._ip, info._port);


}
void TestC_R_Text()
{
	FILE* fin = fopen("test.bin", "r");
	assert(fin);
	ServerInfo info;
	fscanf(fin, "%s%d", info._ip, &info._port);
	fclose(fin);
	printf("%s:%d\n", info._ip, info._port);
}
void TestC_W_TXT()
{
	FILE* fout = fopen("test.txt", "w");
	assert(fout);
	ServerInfo info = { "127.0.0.1", 80 };
	fprintf(fout, "%s\n%d", info._ip, info._port);
	fclose(fout);

}
template<class T1,class T2>
class Data
{
public:
	Data()
	{
		cout << "data<T1, T2>" << endl;
	}
private:
	T1 _d1;
	T2 _d2;
};
template<>
class Data < int, char >
{
public:
	Data() { 
		cout << "Data<int, char>" << endl;
	}
private:
	int _d1;
	char _d2;
};
template<class T1 >
class Data < T1, char >
{
public:
	Data() {
		cout << "Data<T1, char>" << endl;
	}
private:
	T1 _d1;
	char _d2;
};
template<typename T1, typename T2>
class Data<T1*, T2*>
{
public:
	Data()

	{
		cout << "Data<T1*, T2*>" << endl;
	}
private:
	T1 d1;
	T2 d2;
};

template<size_t N>
class A
{
public:
	A() { cout << "A<100>" << endl; }
};
template<>
class A<10>
{
public:
	A() { cout << "A<10>" << endl; }
};
class ConfigManager
{
public:
	ConfigManager(const char* filename)
		:_filename(filename)
	{

	}
	void writeBin(const ServerInfo& info)
	{
		ofstream ofs(_filename.c_str(), ios_base::out | ios_base::binary);
		ofs.write((const char*)&info, sizeof(ServerInfo));
	}
private:
	string _filename;
};
int main()
{
	/*Data<int, int> d1;*/
	/*Date d1;
	cin >> d1;
	cout << d1;*/
	//Data<double,char> d;
	//Data<int*, int*> d;
	//A<10> a;
	//Test_W_Bin();
	//TestC_R_Bin();
	//TestC_R_Text();
	//TestC_W_TXT();	
	ServerInfo winfo = { "127.0.0.1",80 };
	ConfigManager cm("config.bin");
	cm.writeBin(info);

	
}