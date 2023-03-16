#pragma once
#include<vector>
#include<iostream>
#include<utility>
using namespace std;
//���ϱ��
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
	Status _status;//��ĳһ��λ�ý���һ�����

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
		//��������Ϊ0.7����������ԽС��ͻ�ĸ���Խ�ͣ�Ч��Խ�ߣ��ռ��˷�Խ��
		HashData* ret = find(kv.first);
		if (ret != nullptr)
		{
			return false;
		}
		if (_n * 10 / _tables.size() > 7||_tables.size()==0)
		{
			//����
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
		//����̽�⣬����λ�õ�ֵ�Ƚ϶�ͻᷢ����̤�������������������̽��
		while (_tables[index]._status == EXIST)
		{
			i++;
			//index = start + i*i;����̽��
			index = start + i;
			index %= _tables.size();
		}
		_tables[index]._kv = kv;
		_tables[index]._status = EXIST;
		++_n;//��Чλ��Ҳ����
		return true;
	}
private:
	vector<HashData<K, V>> _tables;
	size_t _n=0;//��Ч���ݸ���

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