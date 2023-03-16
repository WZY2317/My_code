#pragma once
enum color
{
	RED,
	BLACK

};
template<class T>
class RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;
	color _col;
	RBTreeNode(const T& data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
		, _data(data)
	{}

};
template<class T>
struct RBTreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef RBTreeIterator<T> Self;

	RBTreeIterator(Node* pNode)
		: _pNode(pNode)
	{}

	// 让迭代器具有类似指针的行为
	T& operator*()
	{
		return _pNode->_data;
	};
	T* operator->()
	{
		return &_pNode->_data;
	}

	// 然迭代器可以移动：前置/后置++  
	Self& operator++()
	{
		Increament();
		return this;
	}
	Self operator++(int)
	{
		Self tmp = this;
		Increament();
		return tmp;
	}
	// 然迭代器可以移动：前置/后置-- 
	Self& operator--()
	{
		DeIncreament();
		return this;
	}
	Self operator--(int)
	{
		self tmp = this;
		DeIncreament();
		return tmp;
	}

	// 让迭代器可以比较
	bool operator!=(const Self& s)const
	{
		return _pNode != s._pNode;
	}
	bool operator==(const Self& s)const
	{
		return _pNode == s._pNode;
	}

private:
	void Increament()
	{
		if (_pNode->_right)
		{
			Node* min = _pNode->_right;
			while (min->_left)
			{
				min = min->_left;
			}
			_pNode = min;
		}
		else
		{
			Node* cur = _pNode;
			Node* parent = cur->_parent;
			while (parent && cur = parent->_right)
			{
				cur = cur->_parent;
				parent = parent->_parent;
			}
			_node = parent;
		}
		
	}
	void DeIncreament()
	{
		if (_pNode->_parent->_parent == _pNode && _pNode->_col == RED)
		{
			_pMode = _pNode->_right;
		}
		else if (_pNode->_left)
		{
			_pNode = _pNode->_left;
			while (_pNode->_right)
			{
				_pNode = _pNode->_right;
			}
		
		}
		else
		{
			Node* pParent = _pNode->_parent;
			while (pParent->_right == _pNode)
			{
				_pNode = pParent;
				pParent = _pNode->_parent;
			}
		}
	}
	Node* _pNode;
};


// T: 可能是键值对<key,value>
//    可能是一个key
// 不论节点中存储的是<key, value> || key, 都是按照key来进行比较的
// KeyOfValue: 提取data中的Key
template<class T, class KeyOfValue>
class RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef RBTreeIterator<T> iterator;
public:
	RBTree()
		: _size(0)
	{
		_pHead = new Node;
		_pHead->_pLeft = _pHead;
		_pHead->_pRight = _pHead;
	}

	// 插入值为data的节点
	// 返回值含义：iterator代表新插入节点   bool：代表释放插入成功
	pair<iterator, bool> Insert(const T& data);

	// Begin和End迭代器
	iterator Begin()
	{
		Node* min = _pHead;
		while (min&&min->_left)
		{
			min = min->_left;
		}
		return iterator(min);
	}
	iterator End()
	{
		return iterator(nullptr);
	}

	// 红黑树是否为红，是返回true，否则返回false
	bool Empty()const
	{
		return !!Begin():
	}
	// 返回红黑树中有效节点的个数
	size_t Size()const
	{
		 return NodeCount(pHead);
	}
	int NodeCount(Node* pNode)
	{
		if (pNode == nullptr)
			return 0;
		else
			return NodeCount(pNode->_left) + NodeCount(pNode->_right) + 1;
	}
	// 将红黑树中的有效节点删除，注意：删除的是有效节点，不删除头结点
	void Clear();
	// 在红黑树中查找data，存在赶回该节点对应的迭代器，否则返回End()
	iterator Find(const T& data);

private:
	Node* _LeftMost()
	{
		if (_pHead->_left)
		{
			Node* pNode = _pHead->_left;
			while (pNode)
			{
				pNode = pNode->_right;
			}
			return pNode;
		}
		else
		{
			return pNode;
		}
	}
	Node* _RightMost()
	{
		if (_pHead->_right)
		{
			Node* pNode = _pHead->_right;
			while (pNode)
			{
				pNode = pNode->_left;
			}
			return pNode;
		}
		else
		{
			return pNode;
		}
	}
	void _Destroy(Node*& pRoot)
	{
		delete(pRoot);
	}
	void RotateL(Node* pParent)
	{
		Node* subL = pParent->_left;
		Node* subLR = subL->_right;
		pParent->_left = subLR;
		if (subLR)
		{
			subLR->_parent = pParent;
		}
		subL->_right = pParent;
		//保存pParent的父节点；
		Node* ppParent = pParent->_parent;
		pParent->_parent = subL;
		if (ppParent == NULL)
		{
			_pHead = subL;
			subL->_parent = NULL;
		}
		else
		{
			
			if (ppParent->_left = pParent)
			{
				ppParent->_left = subL;
			}
			else
			{
				ppParent->_right = subL;
			}
		}

	}
	void RotateR(Node* pParent)
	{
		Node* subR = pParent->_right;
		Node* subRL = subR->_left;
		pParent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = pParent;;
		}
		subR->_left = pParent;
		Node* ppParent = pParent->_parent;
		pParent->_parent = subR;
		if (ppParent == NULL)
		{
			_pHead = subR;
			subR->_parent == NULL;
		}
		else
		{
			if (ppParent->_left == pParent)
			{
				ppParent->_left = subR;
			}
			else
			{
				ppParent->_right = subR;
			}
		}

	}
private:
	Node* _pHead;
	size_t _size;
};
