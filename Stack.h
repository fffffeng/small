#pragma once

#include<iostream>
#include<stdio.h>
#include<assert.h>
using namespace std;

template <class T>

class Stack
{
public:
	Stack()
	: _pdata(NULL)
	, _size(0)
	, _capacity(0)
	{}
	~Stack()
	{
		if (_pdata)
		{
			delete[] _pdata;
			_pdata = NULL;
		}
	}

	bool Empty()
	{
		return _size == 0;
	}
	size_t Size()
	{
		return _size;
	}
	T& Top()
	{
		assert(_size > 0);
		return _pdata[--_size];
	}
	void push(const T& x)
	{
		//if (_pdata == NULL)
		//{
		//	_pdata = new T[sizeof(T)];
		//	_pdata[_size] = x;
		//	++_size;

		//}
		_CheckCapacity();
		_pdata[_size] = x;
		++_size;
	}

	void Pop()
	{
		--_size;
	}
	void _CheckCapacity()
	{
		if (_size == _capacity)
		{
			size_t newcapacity = (_capacity == 0) ? 1 : 2 * _capacity;
			//size_t newcapacity = 2 * _capacity + 3;
			T* tmp = new T[newcapacity];
			for (size_t i = 0; i < _size; ++i)
			{
				tmp[i] = _pdata[i];
			}
			delete[] _pdata;
			_pdata = tmp;
			_capacity = newcapacity;
		}
	}
	void print()
	{
		assert(_size > 0);
		for (size_t i = 0; i < _size; ++i)
		{
			cout << _pdata[i] << " ";
		}
		cout << endl;
	}
protected:
	T* _pdata;
	T _size;
	T _capacity;
};

void testSatck()
{
	Stack<int> s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.print();
	cout << s.Size() << endl;
	cout << s.Top() << endl;
}
//---------------------------
//使用双向链表实现一个队列
//---------------------------
struct listNode
{
	int data;
	listNode* next;
	listNode* prev;
	listNode(int x)
	{
		data = x;
		next = NULL;
		prev = NULL;
	}
};

class myqueue
{
public:
	myqueue()
		:head(NULL)
		, tail(NULL)
	{}
	void Push(int x)
	{
		listNode* node = new listNode(x);
		if (head == NULL)//第一次插入
		{
			head = node;
			tail = node;
		}
		else 
		{
			node->prev = tail;
			tail->next = node;
			tail = node;
		}
	}
	void Pop()
	{
		if (head == NULL)
		{
			cout << "error:the queue is NULL" << endl;
			return;
		}
		if (head->next == NULL)
		{
			delete(head);
			head = NULL;
			tail = NULL;
		}
		else
		{
			head = head->next;
			delete(head->prev);
			head->prev = NULL;
		}
	}
	int Top()
	{
		if (head == NULL)
		{
			cout << "error:the queue is NULL" << endl;
			return;
		}
		else
			return head->data;
	}
private:
	listNode* head;
	listNode* tail;
};

int main()
{
	myqueue q;
	q.Push(1);
	q.Push(2);
	q.Push(3);
	q.Pop();
	q.Pop();
	q.Pop();
	system("pause");
	return 0;
}
