#pragma once
#include<vector>
#include<iostream>
#include<utility>
using namespace std;
//加上标记
enum Status
{
	EXIST,
	EMPTY,
	DELETE
};
template<class K,class V>
struct HashData
{
	pair<K, V> _kv;
	Status _status;//把某一个位置进行一个标记

};
template<class K,class V>
class HashTable
{
public:
	HashData* find(const K& key)
	{
		if (_tables.size == 0)
		{
			return nullptr;
		}
		size_t index = key % _tables.size();
		size_t i = 0;
		size_t start = index + i;
		while (_tables[index]._status != EMPTY)
			
		{
			if (_tables[index]._kv.first == key)
			{
				return &_tables[index];
			}
			++i;
			index = start + i;
			index %= _tables.size();
		}
		return nullptr;
	}
	bool Insert(const pair<K, V>& kv)
	{
		//负载因子为0.7，负载因子越小冲突的概率越低，效率越高，空间浪费越多
		HashData* ret = find(kv.first);
		if (ret != nullptr)
		{
			return false;
		}
		if (_n * 10 / _tables.size() > 7||_tables.size()==0)
		{
			//扩容
			size_t newSize = _tables.size() == 0 ? 10 : _tables.size() * 2;
			//vector<HashData<K, V>> newTables;
			//_tables.resize(newSize);
			/*for (size_t i = 0; i < _tables.size(); ++i)
			{

			}
			_tables.swap(newTables);*/
			HashTable<K, V> newHT;
			newHT._tables.resize(newSize);
			for (size_t i = 0; i < _tables.size(); i++)
			{
				if (_tables[i]._status == EXIST)
				{
					newHT.Insert(_tables[i]._kv);
				}
			}
			_tables.swap(newHT._tables);
		}
		size_t start = kv.first % _tables.size();
		size_t i = 0;
		size_t index = start ;
		//线性探测，连续位置的值比较多就会发生踩踏现象，所以我们引入二次探测
		while (_tables[index]._status == EXIST)
		{
			i++;
			//index = start + i*i;二次探测
			index = start + i;
			index %= _tables.size();
		}
		_tables[index]._kv = kv;
		_tables[index]._status = EXIST;
		++_n;//有效位置也加上
		return true;
	}
private:
	vector<HashData<K, V>> _tables;
	size_t _n=0;//有效数据个数

};
void testHash()
{
	HashTable<int, int> ht;
	int a[] = { 2,12,32,42,52,62,72 };
	for (auto e : a)
	{
		ht.Insert(make_pair(e,e));
	}

}