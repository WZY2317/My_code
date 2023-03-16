#pragma once
template<class K,class V>
struct BSTreeNode
{
	BSTreeNode<K,V>* _left;
	BSTreeNode<K,V>* _right;
	K _key;
	V _value;
	BSTreeNode(const K& key)
		:_left(nullptr)
		, _right(nullptr)
		,_key(null)
		, _value(NULL)
	{}

};
template<class K, class V>
class BSTree
{
	typedef BSTreeNode<K, V> Node;
public:
	BSTree()
		:_root(nullptr)
	{}
	bool Insert(const K& key, const V& value)
	{
		if (_root == nullptr)
		{
			_root = new Node<key, value>;
			return true;
		}
		node* parent=nullptr;
		node* cur=_root;
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
		cur = new Node<key, value>;
		if (cur->_key > parent->_key)
		{
			parent->_right = cur;
		}
		else
		{
			parent = > _left = cur;
		}
		return true;
	}
	Node* Find(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
				return cur;
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
				cur = cur->_left;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				if (cur->_left = nullptr)
				{
					if (parent == nullptr)//ֻ��һ�����ڵ��ʱ��
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_left = cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
						delete cur;
					}
				}
				else
				{
					Node* minparent = cur;
					Node* min = cur -> _right;
					while (min->_left)
					{
						minparent = cur;
						cur = cur->_left;
					}
					cur->_key = min->_key;
					if (minparent->_left == min)
						minparent->_left = min->_right;
					else
						minparent->_right = min->_right;
					delete min;

				}
				return trye;
			}
		}
	}
	void _InOrder(Node* root)
	{
		if (_root == nullptr)
			return;
		_InOrder(_root->_left);
		cout << _root->_value << " ";
		_InOrder(_root->_right);
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
private:
	Node* _root = nullptr;
};



void TestBSTree()
{
	BSTree<string, string> dict;
	dict.Insert("insert", "����");
	dict.Insert("erase", "ɾ��");
	dict.Insert("left", "���");
	dict.Insert("string", "�ַ���");

	string str;
	while (cin >> str)
	{
		auto ret = dict.Find(str);
		if (ret)
		{
			cout << str << ":" << ret->_value << endl;
		}
		else
		{
			cout << "����ƴд����" << endl;
		}
	}

	string strs[] = { "ƻ��", "����", "ƻ��", "ӣ��", "ƻ��", "ӣ��", "ƻ��", "ӣ��", "ƻ��" };
	// ͳ��ˮ�����ֵĴ�
	BSTree<string, int> countTree;
	for (auto str : strs)
	{
		auto ret = countTree.Find(str);
		if (ret == NULL)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_value++;
		}
	}
	countTree.InOrder();
}


