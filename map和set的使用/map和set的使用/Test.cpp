#include<iostream>
#include<utility>
#include<string>
#include<map>
#include<set>
using namespace std;
void testpair()
{
	pair<string, double> pair1;//����Ĭ�Ϲ��캯��
	pair<string, string> pair2("apple", "ƻ��");
	pair<string, string>  pair3(pair2);//construct pair3 with 2;
	pair<string, string> pair4(make_pair("apple", "ƻ��"));//use mobile constructor
	pair2.first = "pear";
	pair2.swap(pair3);
	cout << "pair1:" << pair1.first << " " << pair1.second << endl;
	cout << "pair2:" << pair2.first << " " << pair2.second << endl;
	cout << "pair3:" << pair3.first << " " << pair3.second << endl;
	cout << "pair4:" << pair4.first << " " << pair4.second << endl;
	if (pair2.first != pair3.first)
	{
		cout << "!=" << endl;
	}
}
void testmap()
{
	map<string, int> myMap{make_pair("apple",1),make_pair("pear",2)};
	map<string, int> newmap(myMap);
	map<string, int> newMap(myMap.begin(), myMap.end());
	int value = myMap["pp"];
	for (auto e : newMap)
	{
		cout << e.first << " " << e.second << endl;

	}
	for (auto iter = myMap.begin(); iter != myMap.end(); iter++)
	{
		cout << iter->first << " " << iter->second << endl;
	}
	
	cout << value << endl;
	cout << myMap.at("pear") << endl;

}
void testset()
{
	multiset<int> s;
	s.insert(8);
	s.insert(8);
	s.insert(8);
	s.insert(5);
	s.insert(4);
	s.insert(9);
	s.insert(5);
	set<int>::iterator pos = s.find(8);
	//s.erase(pos);
	//s.erase(9);
	//s.erase(pos, s.end());
	while (pos != s.end() && *pos == 8)
	{
		s.erase(pos);
		pos++;
	}//�Ѿ�ɾ���ĵ��������ܽ���++����������������ʧЧ�����⡣
	for (auto e : s)
	{
		cout << e << endl;
	}
}
void testmap1()
{
	map<string, string> dict;
	pair<string, string> kv1("sort", "����");
	dict.insert(kv1);
	dict.insert(make_pair("test", "����"));
	auto it = dict.begin();
	while (it != dict.end())
	{
		cout << (*it).first << " " << (*it).second<< endl;
			++it;
	}
	for (auto& e : dict)//������pair���������ã�ֱ��ǳ����������������ۻ��С
	{
		cout << e.first << ":" << e.second << endl;
	}

}
void testInsert()
{
	map<string, int> mymap{ {"apple",1}};
	pair<string, int> s = { "pear",2 };
	pair<map<string, int>::iterator, bool> ret;
	ret = mymap.insert(s);
	cout << ret.first->first << ret.second << endl;

}
void count()
{
	string arr[] = { "ƻ��","����","����","����" "����","����" };
	map<string, int> countmap;
	/*for (auto& e : arr)
	{
		auto ret = countmap.find(e);
		if (ret == countmap.end())
		{
			countmap.insert(make_pair(e, 1));
		}
		else
		{
			ret->second++;
		}
	}*/
	for (auto& str : arr)
	{
		auto kv = countmap.insert(make_pair(str, 1));
		if (kv.second == false)
		{
			kv.first->second++;
		}
	}
	for (auto& kv : countmap)
	{
		cout << kv.first << ":" << kv.second << endl;
	}
	for (auto& e : arr)
	{
		countmap[e]++;//���ص���pair�е�second�����ã�Ҳ����key_type������
	}

}
void test()
{
	map<string, int> si;
	si.insert(make_pair("ping", 1));
	si.insert(make_pair("pear", 2));
	si["ping"] = 3;
	si["jk"] = 4;
	cout << si["jk"] << endl;

}
int main()
{
	
	//testmap();
	//testInsert();
	//testset();
	//testmap1();
	//count();
	test();
}