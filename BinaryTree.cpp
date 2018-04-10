#include<stdio.h>
#include<iostream>
using namespace std;

typedef struct Node
{
	int _data;
	struct Node* _left;
	struct Node* _right;

	Node(const int& x)
	{
		_data = x;
		_left = NULL;
		_right = NULL;
	}
}Node;

class BinaryTree
{
public:
	BinaryTree()
	{
		_root = NULL;
	}
	//根据数组先序构造二叉树
	BinaryTree(const int* a, size_t n, const int& invalid)
	{
		int index = 0;
		_root = _CreateTree(a, n, invalid, index);
	}
	~BinaryTree()
	{
		_DeleteTree(_root);
		_root = NULL;
	}

	//先序递归遍历
	void PrevOrder()
	{
		_PrevOrder(_root);
	}

	//中序递归遍历
	void InOrder()
	{
		_InOrder(_root);
	}
	
	//后序递归遍历
	void PostOrder()
	{
		_PostOrder(_root);
	}

private:
	void _PrevOrder(Node* root)
	{
		if (root == NULL)
			return;
		cout << root->_data << " ";
		_PrevOrder(root->_left);
		_PrevOrder(root->_right);
	}
	void _InOrder(Node* root)
	{
		if (root == NULL)
			return;
		_InOrder(root->_left);

		cout << root->_data << " ";

		_InOrder(root->_right);
	}
	void _PostOrder(Node* root)
	{
		if (root == NULL)
			return;
		_PostOrder(root->_left);
		_PostOrder(root->_right);

		cout << root->_data << " ";

	}
	Node* _CreateTree(const int* a, size_t n, const int& invalid,  int& index)
	{
		Node* root = NULL;
		if (index < n&&a[index] != invalid)
		{
			root = new Node(a[index]);
			root->_left = _CreateTree(a, n, invalid, ++index);
			root->_right = _CreateTree(a, n, invalid, ++index);
		}
		return root;
	}
	void _DeleteTree(Node* root)
	{
		if (root == NULL)
			return;
		_DeleteTree(root->_left);
		_DeleteTree(root->_right);
		delete root;
	}

	Node* GetRoot()
	{
		return _root;
	}

	Node* _root;
};
//---测试--------
void test()
{
	int a[] = { 1, 2, 3, '#', '#', 4, '#', '#', 5, 6 };
	BinaryTree tree(a, sizeof(a) / sizeof(a[0]), '#');
	cout << "先序遍历：";
	tree.PrevOrder();
	cout << endl;
	cout << "中序遍历：";
	tree.InOrder();
	cout << endl;
	cout << "后序遍历：";
	tree.PostOrder();
}
//-----主函数----
int main()
{
	test();
	system("pause");
	return 0;
}