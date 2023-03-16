#pragma once
#include<vector>

enum Status
{
	EXIST,
	EMPTY,
	DELETE
};
template<class K, class V>
struct HashData
{
	pair<K, V> _kv;
	Status _status = EMPTY;


};
template<class K>
struct Hash
{
	size_t operator(const K& key)
	{
		return key;
	}
};
template<>
struct Hash < string >
{
	size_t operator()(const string& s)
	{
		// BKDR
		size_t value = 0;
		for (auto ch : s)
		{
			value *= 31;
			value += ch;
		}
		return value;
	}
};
//struct HashStr
//{
//	size_t operator()(const string& s)
//	{
//		size_t value = 0;
//		for(auto e : s)
//		{
//			value += e;
//		}
//		return value;
//	}
//};
template<class K,class V,class HashFunc=Hash<K>>
class HashTable
{
public:
	bool Erase(const K& key)
	{
		HashData<K, V>* ret = Find(key);
		if (ret == nullptr)
		{
			return  false;
		}
		else
		{
			ret->_status = DELETE;
			return true;
		}
	}
	HashData<K,V>* Find(const K& key)
	{
		HashFunc hf;
		if (_tables.size() == 0)
			return nullptr;
		size_t start = hf(key) % _tables.size();
		size_t i = 0;
		size_t index = start + i;
		while (_tables[index]._status != EMPTY)
		{
			if (_tables[index]._kv.first == key&&_tables[index]._status==EXIST)
			{
				return &_tables[index];
			}
			i++;
			index = start + i;
			index %= _tables.size();
		}
		return nullptr;
	}
	bool Insert(const pair<K, V>& kv)
	{
		HashData<K, V>* ret= Find(kv.first);
		if (ret)
		{
			return false;
		}
		//负载因子到0.7就扩容
		if (_tables.size()==0||10 * _n / _tables.size() > 7)
		{
			size_t newSize =_tables.size() ==0 ? 10 : _tables.size() * 2;
			HashTable<K,V,HashFunc> newTables;
			newTables._tables.resize(newSize);
			//遍历原表，把原表的数据映射到新表
			for (int i = 0; i < _tables.size(); ++i)
			{
				if (_tables[i]._status == EXIST)
				{
					newTables.Insert(_tables[i]._kv);
				}
			}
			_tables.swap(newTables._tables);

		
		}
		/*if (_tables.size() == 0)
		{
			return nullptr;
		}*/
		HashFunc hf;
		size_t start = hf(kv.first) % _tables.size();
		int i = 0;
		size_t index = start + i;
		//线性探测
		while (_tables[index]._status == EXIST)
		{
			i++;
			index = start + i;
			index %= _tables.size();
		}
		//二次探测
		/*while (_tables[index]._status == EXIST)
		{
			i++;
			index = start + i*i;
			index %= _tables.size();
		}*/
		_tables[index]._kv = kv;
		_tables[index]._status = EXIST;
		++_n;
		return true; 
		
	}
private:
	vector<HashData<K,V>> _tables;
	size_t _n=0;
};
namespace LinkHash
{
	template<class K, class V>
	struct HashNode
	{
		pair<K, V> _kv;
		HashNode<K, V>* _next;
		HashNode(const pair<K, V>& kv)
			:_kv(kv)
			,_next(nullptr)
		{

		}
	};
	template<class K, class V, class HashFunc=Hash<K> >
	class HashTable
	{
		typedef HashNode<K, V> Node;
	public:
		boo Erase(const K& key)
		{
			if (_tables.empty())
				return false;
			HashFunc hf;
			size_t index = hf(key) % _tables.size();
			Node* cur = _tables[index];
			Node* prev = nullptr;
			while (cur)
			{
				if (cur->_kv, first == key)
				{
					if (prev == nullptr)
					{
						prev->_next = cur;
					}
					else
					{
						prev->_next = cur->_next;
					}
					delete cur;
					return true;
				}
				else
				{
					prev = cur;
					cur = cur->_next;
				}
			}
			return false;
			return nullptr;
		}
		Node* Find(const K& key)
		{
			HashFunc hf;
			if (_tables.empty())
				return nullptr;
			size_t index = hf(key) % _tables.size();
			Node* cur = _tables[index];
			while (cur)
			{
				if (cur->_kv, first == key)
				{
					return cur;
				}
				else
				{
					cur = cur->_next;
				}
			}
			return nullptr;
		}
		bool Insert(const pair<K, V>& kv)
		{
			Node* ret = Find(kv.first);
			if (ret)
			{
				return false;
			}
			if (n == _tables.size())
			{
				size_t newSize = _tables.size() == 0 ? _tables.size() * 2;
				vector<Node*> newTables;
		 		newTables.resize(newSize);
				for (size_t i = 0; i < _tables.size(); i++)
				{
					Node* cur = _tables[i];
					while (cur)
					{
						Node* next = cur->_next;
						size_t index = hf(cur->_kv.first) % newTables.size();
						cur->_next = _tables[index];
						_tables[index] = cur;
						cur = cur->_next;
					}
				}
			}
			HashFunc hf;
			size_t index = hf(kv.first) % _tables.size();
			Node* newNode = new Node(kv);
			newNode->_next = _tables[index];
			_tables[index] = newNode;
			++_n;
			return true;
		}
	private:
		vector<Node*> _tables;
		size_t _n = 0;  // 有效数据的个数
	};
}
void TestHashTable()
{
	HashTable<int, int,Hash<int>> HT;
	int a[] = { 2,12,32,42,52,62,72 };
	for (auto e : a)

		HT.Insert(make_pair(e, e));
	cout <<HT.Find(32) << endl;
}
void TestHashTable2()
{
	/*HashStr hs;
	cout << hs("sort")<<endl;
	cout << hs("insert") << endl;
	cout << hs("eat") << endl;
	cout << hs("ate") << endl;
	cout << hs("abcd") << endl;
	cout << hs("aadd") << endl;*/

	HashTable<string, string> ht;
	ht.Insert(make_pair("sort", "排序"));
	ht.Insert(make_pair("string", "字符串"));

	// 当key是一个定义类型时，需要配置一个仿函数，将key转成整形
	//HashTable<Date, string, HashDate> htds;
}