#pragma once
#include"RBTree.h"
namespace wzy   // Ϊ�˷�ֹ�ظ�,��ͬѧ���Լ���ȡ�����ռ�����֣����򲩿���ȫ����һ���ģ�����ʱ������
{
	template<class K, class V>
	class map
	{
		typedef pair<K, V> ValueType;
		struct KeyOfValue
		{
			const K& operator()(const ValueType& data)
			{
				return data.first;
			}
		};

		typedef RBTree<ValueType, KeyOfValue> RBTree;
		typename typedef RBTree::iterator iterator;
	public:
		map() : t() {}

		/////////////////////////////
		// iterator��beign��end
		iterator begin()
		{
			return t.Begin();
		}
		iterator end()
		{
			return t.End();
		}

		///////////////////////////////
		// capacity
		bool empty()const;
		size_t size()const;

		///////////////////////////////
		// access
		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = t.insert(make_pair(key, V()));
			return ret.first->second;
		}

		///////////////////////////////
		// modify
		pair<iterator, bool> insert(const ValueType& data)
		{
			return t.Insert(data);
		}
		void clear();
		iterator find(const K& key);
	private:
		RBTree t;
	};
}
