#define _CRT_SECURE_NO_DEPRECATE 1

#include"AVL.h"


template <typename K, typename V>
AVLTree<K, V>::AVLTree()
{
	_root = NULL;
}

template <typename K, typename V>
bool AVLTree<K, V>::Insert(const K& key, const V& value)
{
	//1，空树
	//2,不是空树：找到插入节点位置-->插入节点-->更新平衡因子
	if (_root == NULL)
	{
		_root = new Node(key, value);
		return true;
	}

	//不是空树情况：
	Node* parent = NULL;
	Node* cur = _root;

	//找应该插入的位置:
	while (cur)
	{
		if (cur->_key > key)
		{
			parent = cur;
			cur = cur->_left;
		}
		else if (cur->_key < key)
		{
			parent = cur;
			cur = cur->_right;
		}
		else
			return false;
	}
	//插入数据
	cur = new Node(key, value);
	cur->_parent = parent;
	if (parent->_key > key)
		parent->_left = cur;
	else
		parent->_right = cur;
	//调节平衡因子
	while (parent)
	{
		if (cur == parent->_left)
			parent->_bf--;
		else if (cur == parent->_right)
			parent->_bf++;
		if (parent->_bf == 0)
			break;
		else if (parent->_bf == 1 || parent->_bf == -1)
		{
			cur = parent;
			parent = parent->_parent;
		}

		else
		{
			if (parent->_bf == -2)
			{
				Node* SubL = parent->_left;
				if (SubL->_bf == -1)
					RotateR(parent);
				else
					RotateLR(parent);
			}
			else if (parent->_bf == 2)
			{
				Node* SubR = parent->_right;
				if (SubR->_bf == 1)
					RotateL(parent);
				else
					RotateRL(parent);
			}
			break;
		}

	}
	return true;
}

template <class K, class V>
void AVLTree<K, V>::RotateL(Node* parent)
{
	Node* SubR = parent->_right;
	Node* SubRL = SubR->_left;
	
	parent->_right = SubRL;
	if (SubRL)
		SubRL->_parent = parent;
	SubR->_left = parent;
	Node* ppNode = parent->_parent;//保存parent的父亲
	parent->_parent = SubR;
	if (ppNode == NULL)
	{
		_root = SubR;
		SubR->_parent = NULL;
	}
	else
	{
		if (ppNode->_left == parent)
			ppNode->_left = SubR;
		else if (ppNode->_right == parent)
			ppNode->_right = SubR;
		SubR->_parent = ppNode;
	}  
	SubR->_bf = parent->_bf = 0;
}

template <class K, class V>
void AVLTree<K, V>::RotateR(Node* parent)
{
	Node* SubL = parent->_left;
	Node* SubLR = SubL->_right;
	parent->_left = SubLR;
	
	if (SubLR)
		SubLR->_parent = parent;

	SubL->_right = parent;
	Node* ppNode = parent->_parent;//保存parent的父亲
	parent->_parent = SubL;

	if (ppNode == NULL)
	{
		_root = SubL;
		SubL->_parent = NULL;
	}
	else
	{
		if (ppNode->_left == parent)
			ppNode->_left = SubL;
		else if (ppNode->_right == parent)
			ppNode->_right = SubL;
		SubL->_parent = ppNode;
	}
	SubL->_bf = parent->_bf = 0;
}

template <class K, class V>
void AVLTree<K, V>::RotateLR(Node* parent)
{
	Node* SubL = parent->_left;
	Node* SubLR = SubL->_right;
	int bf = SubLR->_bf;
	RotateL(parent->_left);
	RotateR(parent);

	if (bf == 0)
	{
		SubLR->_bf = parent->_bf = 0;
	}
	else if (bf == 1)
	{
		parent->_bf = 0;
		SubL->_bf = -1;
		SubLR->_bf = 0;
	}
	else
	{
		SubL->_bf = 0;
		parent->_bf = 0;
		SubLR->_bf = 1;
	}
}

template <class K, class V>
void AVLTree<K, V>::RotateRL(Node* parent)
{
	Node* SubR = parent->_right;
	Node* SubRL = SubR->_left;
	int bf = SubRL->_bf;

	RotateR(parent->_right);
	RotateL(parent);

	if (bf == 0)
	{
		SubRL->_bf = parent->_bf = 0;

	}
	else if (bf == 1)
	{
		parent->_bf = 0;
		SubR->_bf = -1;
		SubRL->_bf = 0;
	}
	else
	{
		parent->_bf = 0;
		SubR->_bf = 1;
		SubRL->_bf = 0;
	}
}

template <class K,class V>
void AVLTree<K, V>::InOrder()
{
	_InOrder(_root);
	cout << endl;
}
template <class K,class V>
void AVLTree<K, V>::_InOrder(Node* root)
{
	if (root == NULL)
		return;
	_InOrder(root->_left);
	cout << root->_key << " ";
	_InOrder(root->_right);
}

template <class K,class V>
int AVLTree<K, V>::GetDepth(Node* root)
{
	if (root == NULL)
		return 0;
	int LeftDepth = GetDepth(root->_left);
	int RightDepth = GetDepth(root->_right);
	return LeftDepth > RightDepth ? LeftDepth + 1 : RightDepth + 1;
}
template <class K,class V>
bool AVLTree<K, V>::IsBalance(Node* root)
{
	Node* cur = root;
	if (cur == NULL)
		return true;
	int leftDepth = GetDepth(cur->_left);
	int rightDepth = GetDepth(cur->_right);
	if (abs(leftDepth - rightDepth) > 1)
		return false;
	else
		return IsBalance(cur->_left) && IsBalance(cur->_right);
}
void test()
{
	AVLTree<int, char> a;
	a.Insert(1, 'a');
	a.Insert(2, 'b');
	a.Insert(3, 'c');
	a.Insert(4, 'd');
	a.InOrder();
	cout << a.GetDepth(a.GetRoot()) << endl;
	cout << a.IsBalance(a.GetRoot()) << endl;


}


