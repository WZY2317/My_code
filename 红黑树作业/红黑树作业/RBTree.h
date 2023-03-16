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

	// �õ�������������ָ�����Ϊ
	T& operator*()
	{
		return _pNode->_data;
	};
	T* operator->()
	{
		return &_pNode->_data;
	}

	// Ȼ�����������ƶ���ǰ��/����++  
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
	// Ȼ�����������ƶ���ǰ��/����-- 
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

	// �õ��������ԱȽ�
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


// T: �����Ǽ�ֵ��<key,value>
//    ������һ��key
// ���۽ڵ��д洢����<key, value> || key, ���ǰ���key�����бȽϵ�
// KeyOfValue: ��ȡdata�е�Key
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

	// ����ֵΪdata�Ľڵ�
	// ����ֵ���壺iterator�����²���ڵ�   bool�������ͷŲ���ɹ�
	pair<iterator, bool> Insert(const T& data);

	// Begin��End������
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

	// ������Ƿ�Ϊ�죬�Ƿ���true�����򷵻�false
	bool Empty()const
	{
		return !!Begin():
	}
	// ���غ��������Ч�ڵ�ĸ���
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
	// ��������е���Ч�ڵ�ɾ����ע�⣺ɾ��������Ч�ڵ㣬��ɾ��ͷ���
	void Clear();
	// �ں�����в���data�����ڸϻظýڵ��Ӧ�ĵ����������򷵻�End()
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
		//����pParent�ĸ��ڵ㣻
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
