#pragma once

template<class K>
struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;
	BSTreeNode(const K& key)
		:_left(nullptr)
		, _right(nullptr)
		, _key(key)
	{

	}
};
template<class K>
struct BSTree
{
	typedef BSTreeNode<K> Node;
public:
	BSTree()
		:_root(nullptr)
	{}
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
				return false;
		}
		cur = new Node(key);
		if (parent->_key < key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}
	bool find(const K& key)
	{
		if (_root == nullptr)
			return false;
		else
		{
			Node* cur = _root;
			
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else
				{
					return true;
				}
			}
			return false;
			
		}
	}
	bool Erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;

			}
			else
			{
				if (cur->_left == nullptr)
				{
					if (parent == nullptr)
					{
						cur = nullptr;
					}
					if (parent->_left == cur)
					{
						parent->_left = cur->_right;
					}
					else
					{
						parent->_right = cur->_right;
					}
					delete cur;
				}
				else if (cur->_right == nullptr)
				{
					if (parent == nullptr)
					{
						_root = cur->_left;
					}
					if (parent->_left == cur)
					{
						parent->_left = cur->_left;
					}
					else
					{
						parent->_right = cur->_left;
					}
				}
				else
				{
					Node* minParent = cur;
					Node* min = cur->_right;
					while (min->_left)
					{
						minParent = min;
						min = min->_left;
					}
					cur->_key = min->_key;
					if (min->_right != nullptr)
					{
						minParent->_left = min->_right;
					}
					else
					{
						minParent->_right = min->_right;
					}
					delete min;
				}
				return true;
			}
			return false;
		}
	}
	Node* FindR(Node* root, const K& key)
	{
		if (root == nullptr)
		{
			return nullptr;
		}
		if (root->_key < key)
		{
			FindR(root->_right, key);
		}
		else if (root->_key > key)
		{
			FindR(root->_left, key);
		}
		else
			return root;
	}
	bool InsertR(Node*& root,const K& key)
	{
		if (root == nullptr)
		{
			root = new Node(key);
			return true;
		}
		if (root->_key < key)
		{
			return Insert(root->_right, key);
		}
		else if (root->_key > key)
		{
			return Insert(root->_left, key);
		}
		else
			return false;
	}
	bool _EraseR(Node*& root, const K& key)

	{
		if (root == nullptr)
			return false;
		if (root->_key < key)
		{
			return _EraseR(root->_right, key);
		}
		else if (root->_key > key)
		{
			return _EraseR(root->_left, key);
		}
		else
		{
			Node* del = root;
			if (root->_left == nullptr)
			{
				root = root->_right;
			}
			else if (root->_right == nullptr)
			{
				root = root->_left;
			}
			else
			{
				Node* min = root->_right;
				while (min->_left)
				{
					min = min->_left;
				}
				swap(min->_key, root->_key);
				_EraseR(root->_right, key);
			}
			delete del;
			return true;

		}
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
private:
	Node* _root;
};