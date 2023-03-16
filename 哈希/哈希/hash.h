#pragma once
#include<vector>

namespace CloseHash {
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
	template<class K, class V>
	class HashTable {
	public:
		bool Insert(const pair<K, V>& kv)
		{

		}

	private:
		vector<HashData<K, V>> _tables;
		int _n;//有效数据个数

	};

}
