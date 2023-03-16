#pragma once
using namespace std;
namespace bit {
	template<class T>
	struct ListNode {
		ListNode<T>* _prev;
		ListNode<T>* _next;
		T _data;
		ListNode(const T& data = T())
			:_next(nullptr)
			,_prev(nullptr)
			, _data(data)
		{}
		
	};
	template<class T>
	struct _list_iterator
	{
		typedef ListNode<T> Node;
		
		Node* _node;
		_list_iterator(Node* x)
			:_node(x)
			
		{

		}
		//«∞÷√++
		_list_iterator& operator++()
		{
			_node = _node->next;
			return *this;
		}
		//∫Û÷√++
		_list_iterator operator++(int)
		{
			_list_iterator<T> tmp(*this);
			_node = _node->_next;
			return tmp;
		}
		bool operator!=(_list_iterator<T>& it)
		{
			return _node != it._node;
		}
		
		T& operator*()
		{
			return _node->_data;
		}

	};
	template<class T>
	class List
	{
		
		typedef ListNode<T> Node;
	public:
		
		typedef _list_iterator<T> iterator;
		List()
		{
			_head = new Node();
			_head->_next = _head;
			_head->_prev = _head;
			

		}
		void push_back(const T& x)
		{
			Node* tail = _head->_prev;
			Node* newNode = new Node(x);
			tail->_next = newNode;
			newNode->_prev = tail;
			newNode->_next = _head;
			_head->_prev = newNode;
		}
		iterator  begin()
		{
			return iterator(_head->_next);
		}
		iterator end()
		{
			return iterator(_head);
		}
	private:
		Node* _head;
		


	};
	void test_List1()
	{
		List<int> L1;
		L1.push_back(1);
		L1.push_back(2);
		L1.push_back(3);
		
		List<int>::iterator it = L1.begin();
		while (it != L1.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;
		
	}
}
