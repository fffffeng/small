#pragma once
#include<stdio.h>
#include<iostream>
using namespace std;
//#ifndef AVL_H
//#define AVL_H
template <typename K, typename V>
struct AVLTreeNode
{
	AVLTreeNode(const K& key, const V& value)
	:_key(key)
	, _value(value)
	, _bf(0)
	, _left(NULL)
	, _right(NULL)
	, _parent(NULL)
	{}
	K _key;
	V _value;
	int _bf;	//平衡因子 = 右子树高度 - 左子树高度
	AVLTreeNode<K,V>* _left;
	AVLTreeNode<K,V>* _right;
	AVLTreeNode<K,V>* _parent;


};
template <typename K, typename V>
class AVLTree
{
	typedef AVLTreeNode<K,V> Node;
public:
	AVLTree();
	//~AVLTree();
	bool Insert(const K& key, const V& value);
	void RotateR(Node* parent); //右旋
	void RotateL(Node* parent);	//左旋
	void RotateLR(Node* parent);	//左右双旋
	void RotateRL(Node* parent);	//右左双旋
	void InOrder();
	int GetDepth(Node* root);
	bool IsBalance(Node* root);
	Node* GetRoot()
	{
		return _root;
	}

private:

	void _InOrder(Node* root);
	Node* _root;
};


//#endif