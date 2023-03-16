#pragma once
#include"RBTree.h"
namespace xxx  // м╛ио
{
	template<class K>
	class set
	{
		typedef K ValueType;

		struct KeyOfValue
		{
			const K& operator()(const ValueType& data)
			{
				return data;
			}
		};

		typedef RBTree<ValueType, KeyOfValue> RBTree;
		typename typedef RBTree::iterator iterator;
	public:
		set() : t() {}
		////////////////////////////
		// iterator: begin/end
		iterator begin()
		{
			return t.begin();
		}
		iterator end()
		{
			return t.end();
		}
		//////////////////////////////
		// capacity
		bool empty()const
		{
			return t.Empty();
		}
		size_t size()const
		{
			return t.Size();
		}
		///////////////////////////
		// modify
		pair<iterator, bool> insert(const ValueType& data)
		{
			return t.Insert(data);
		}
		void clear()
		{
			return t._Destroy();
		}
		iterator find(const K& key)
		{
			return t.Find(key);
		}
	private:
		RBTree t;
	};
}
