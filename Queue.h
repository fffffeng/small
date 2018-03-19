#pragma once
#include<iostream>
using namespace std;


template <class T>
struct ListNode
{
	ListNode(const T&x)
	:_data(x)
	, _next(NULL)
	{}
	T _data;
	ListNode<T>* _next;

};
template <class T>
class Queue
{
	typedef ListNode<T> Node;
public:
	Queue()
		:_head(NULL)
		, _tail(NULL)
	{}
	~Queue()
	{
		Node*  cur = _head;
		if (cur)
		{
			Node* next = cur->_next;
			delete cur;
			cur = next;
		}
	}

	bool Empty()
	{
		return _head == NULL;
	}

	size_t Size()
	{
		size_t count = 0;
		Node* cur = _head;
		while (cur)
		{
			++count;
			cur = cur->_next;
		}
		return count;
	}
	void Push(const T& x)
	{
		Node* tmp = new Node(x);
		if (_head == NULL)
		{
			_head = _tail = tmp;
		}
		else
		{
			_tail->_next = tmp;
			_tail = tmp;
		}
	}

	void Pop()
	{
		assert(_head);
		Node* next = _head->_next;
		delete _head;
		_head = next;
	}

	T& Front()
	{
		assert(_head);
		return _head->_data;
	}

	T& Back()
	{
		assert(_tail);
		return _tail->_data;
	}


protected:
	Node* _head;
	Node* _tail;

	
};

void testQueue()
{
	Queue<int> q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Push(4);
	cout << q.Front() << endl;
	cout << q.Back() << endl;
	cout << q.Size() << endl;
}