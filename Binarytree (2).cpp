//先序非递归遍历
void PrevOrderNOR()
{
	_PrevOrderNOR(_root);
}
void _PrevOrderNOR(Node* root)
{
	Node* cur = root;
	stack<Node*> s;
	while (cur || !s.empty())
	{
		while (cur)
		{
			cout << cur->_data << " ";
			s.push(cur);
			cur = cur->_left;
		}
		Node* front = s.top();
		s.pop();
		cur = front->_right;
	}
}

//中序非递归遍历
void InOrderNOR()
{
	_InOrderNOR(_root);
}
void _InOrderNOR(Node* root)
{
	Node* cur = root;
	stack<Node*> s;
	while (cur || !s.empty())
	{
		while (cur)
		{
			s.push(cur);
			cur = cur->_left;
		}
		Node* front = s.top();
		s.pop();
		cout << front->_data << " ";
		cur = front->_right;
	}
}

//后序非递归遍历
void  PostOrderNOR()
{
	_PosetOrderNOR(_root);
}
void _PosetOrderNOR(Node* root)
{
	Node* cur = root;
	stack<Node*> s;
	Node* prev = NULL;
	while (cur || !s.empty())
	{
		while (cur)
		{
			s.push(cur);
			cur = cur->_left;
		}
		Node* front = s.top();
		if (front->_right == NULL || front->_right == prev)
		{
			cout << front->_data << " ";
			s.pop();
			prev = front;
		}
		else
		{
			cur = front->_right;
		}

	}
}
