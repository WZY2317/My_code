#pragma once
enum color
{
	RED,
	BLACK
};
template<class K,class V>
struct RBTreeNode
{
	RBTree<K, V>* _left;
	RBTree<K, V>* _right;
	RBTree<K, V>* _parent;
	pair<K, V> _kv;
	color _col;
	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
		, _kv(kv)
	{}
};
template<class K, class V>
struct RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree() :_root(nullptr)
	{

	}
	bool InSert(const pair<K,V> &kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		cur->_col = RED;
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		while (parent&& parent->_col = RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;
				}
				else//uncle is not exist or black
				{
					if (cur == parent->_left)
					{
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						RotateL(parent);
						RotateR(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			else
			{
  				//          g                      g
                 //             p                      p
				//                 c                 c

				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					cur = grandfather;
					parent = cur->_parent;
				}
				else//uncle is not exist or black
				{
					if (cur == parent->_right)
					{
						RotateL(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else//uncle 不存在或者为黑色
					{
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}
					break;
				}
			}
			
			
			
		}
		_root->_col = BLACK;
		return true;
		


	}
	void RotateR(Node* parent)
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		Node* parentParent = parent->_parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (parent == _root)
		{
			_root = subL;
			_root->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subL;
			else
				parentParent->_right = subL;

			subL->_parent = parentParent;
		}
	}
	void RotateL(Node* parent)
	{
		Node* subR = parent->_right;
		Node* subRL = subR->_left;

		parent->_right = subRL;
		if (subRL)
		{
			subRL->_parent = parent;
		}

		Node* parentParent = parent->_parent;
		subR->_left = parent;
		parent->_parent = subR;

		if (_root == parent)
		{
			_root = subR;
			subR->_parent = nullptr;
		}
		else
		{
			if (parentParent->_left == parent)
				parentParent->_left = subR;
			else
				parentParent->_right = subR;
			subR->_parent = parentParent;
		}
	}
	void InOrder()
	{
		_InOrder(_root);
	}
	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;
		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);

	}
private:
	Node* _root;
	
};
void testRBTree()
{
	RBTree<int, int> t;
	int a[] = { 4,2,6,1,3,5,15,7,16,14 };
	for (int e : a)
	{
		t.InSert(make_pair(e, e));
	}
	t.InOrder();
}