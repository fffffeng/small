#pragma once
#include<stdio.h>
#include<malloc.h>
#include<assert.h>

typedef int DataType;

typedef struct ListNode
{
	DataType data;
	struct ListNode* next;
}ListNode;

//创建一个结点
ListNode* BuyNode(DataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = x;
	node->next = NULL;
	return node;
}

//尾插
void PushBack(ListNode** pplist, DataType x)
{
	if (*pplist == NULL)
	{
		*pplist = BuyNode(x);
	}
	else
	{
		ListNode* tail = *pplist;
		while (tail->next)
		{
			tail = tail->next;
		}
		tail->next = BuyNode(x);
	}
}
//查找一个结点
ListNode* FindList(ListNode* plist, DataType x)
{
	ListNode* cur = plist;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

//从尾到头打印单链表-----(递归法)
void PrintListFromTailtoHead(ListNode* plist)
{
	ListNode* cur = plist;
	if (cur != NULL)
	{
		PrintListFromTailtoHead(cur->next);
		printf("%d->", cur->data);
	}
}

//删除无头单链表的非尾结点--（把pos->next结点的data给pos的data,然后删除pos->next结点）
void EraseNonTail(ListNode* pos)
{
	assert(pos&&pos->next);
	ListNode* next = pos->next;
	pos->data = next->data;
	pos->next = next->next;//摘结点
	free(next);
}

//在无头单链表的一个结点前插入一个结点
void InsertNonTeal(ListNode *pos, DataType x)
{
	assert(pos);
	ListNode* newnode = BuyNode(x);
	ListNode* next = pos->next;
	pos->next = newnode;
	newnode->next = next;
	newnode->data = pos->data;
	pos->data = x;
}

//单链表实现约瑟夫环
ListNode* JosepRing(ListNode* list, int k)//删除第K个结点，把这个结点的data改成下一个结点的data，然后删除第K个结点的下一个结点。
{
	if (!list)
	{
		return NULL;
	}
	ListNode* cur = list;
	while (cur->next != cur)
	{
		int count = k;
		while (--count)
		{
			cur = cur->next;
		}
		ListNode* next = cur->next;
		cur->data = next->data;
		free(next);
	}
	return cur;
}

//翻转/逆置单链表
ListNode* Reverse(ListNode* list)
{
	ListNode* newlist = NULL;
	ListNode* cur = list;
	while (cur)
	{
		//摘结点
		ListNode* tmp = cur;
		cur = cur->next;
		//插结点--（既在newlist前插入tmp）
		tmp->next = newlist;
		newlist = tmp;
	}
	return newlist;
}

//链表排序（冒泡）
void BubbleSort(ListNode* list)
{
	if (list == NULL&&list->next != NULL)
	{
		return;
	}
	ListNode* tail = NULL;
	while (tail != list->next)
	{
		ListNode* prev = list;
		ListNode* next = prev->next;
		while (next != tail)
		{
			if (prev->data > next->data)//交换两个结点的值，大的放在后
			{
				DataType tmp = next->data;
				next->data = prev->data;
				prev->data = tmp;
			}
			prev = prev->next;
			next = next->next;
		}
		tail = prev;
	}
}

//合并两个有序链表，合并后依然有序
ListNode* Merge(ListNode* list1, ListNode* list2)
{
	if (!list1)
	{
		return list2;
	}
	if (!list2)
	{
		return list1;
	}
	//先找出两个链表中小的一个结点，把它摘下来做新链表的头结点
	ListNode* list = NULL;
	if (list1->data < list2->data)
	{
		list = list1;
		list1 = list1->next;
	}
	else
	{
		list = list2;
		list2 = list2->next;
	}
	//然后开始尾插
	ListNode* tail = list;
	while (list1&&list2)
	{
		if (list1->data < list2->data)
		{
			tail->next = list1;
			list1 = list1->next;
		}
		else
		{
			tail->next = list2;
			list2 = list2->next;
		}
		tail = tail->next;
	}
	if (!list1)
	{
		tail->next = list2;
	}
	if (!list2)
	{
		tail->next = list1;
	}
	return list;
}

//查找链表的中间结点，要求只能遍历一次链表--(快慢指针法)
ListNode* FindMidNode(ListNode* list)
{
	if (!list)
	{
		return NULL;
	}
	ListNode* slow = list;
	ListNode* fast = list;
	while (fast&&fast->next)
	{
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
}

//查找链表倒数第K个结点，要求只能遍历一次链表----（快慢指针法）
ListNode* FindTail_k_Node(ListNode* list,int K)
{
	ListNode* slow = list;
	ListNode* fast = list;
	while (--K)
	{
		if (fast == NULL)//fast为空说明K值大于链表长度。既K值无效
		{
			return NULL;
		}
		fast = fast->next;
	}
	while (fast->next)
	{
		slow = slow->next;
		fast = fast->next;
	}
	return slow;
}

//打印链表
void PrintList(ListNode* plist)
{
	if (!plist)
	{
		printf("->NULL\n");
		return;
	}
	else
	{
		ListNode* cur = plist;
		while (cur)
		{
			printf("%d->", cur->data);
			cur = cur->next;
		}
		printf("NULL\n");
		return;
	}
	/*ListNode* cur = plist;
	while (cur)
	{
		printf("%d->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
	return;*/
}

void TestList1()
{
	ListNode* list = NULL;
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PrintList(list);
	PrintListFromTailtoHead(list);
}

void TestList2()
{
	ListNode* list = NULL;
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PrintList(list);
	ListNode* pos = FindList(list, 3);
	EraseNonTail(pos);
	PrintList(list);
}
void TestList3()
{
	ListNode* list = NULL;
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 5);
	PrintList(list);
	ListNode* pos = FindList(list, 1);
	InsertNonTeal(pos, 4);
	PrintList(list);
}
void TestList4()
{
	ListNode* list = NULL;
	PushBack(&list, 1);
	PushBack(&list, 2);
	PushBack(&list, 3);
	PushBack(&list, 4);
	PushBack(&list, 5);
	ListNode* reverselist = Reverse(list);
	PrintList(reverselist);
}
void TestList5()
{
	ListNode* list = NULL;
	PushBack(&list, 8);
	PushBack(&list, 2);
	PushBack(&list, 1);
	PushBack(&list, 3);
	PushBack(&list, 6);
	PrintList(list);
	BubbleSort(list);
	PrintList(list);
}
void TestList6()
{
	ListNode* list1 = NULL;
	PushBack(&list1, 1);
	PushBack(&list1, 3);
	PushBack(&list1, 5);
	PushBack(&list1, 7);
	PushBack(&list1, 6);
	PrintList(list1);
	ListNode* list2 = NULL;
	PushBack(&list2, 2);
	PushBack(&list2, 4);
	PushBack(&list2, 6);
	PushBack(&list2, 8);
	PushBack(&list2, 9);
	PrintList(list2);
	ListNode* list = Merge(list1, list2);
	PrintList(list);
	
	ListNode* mid = FindMidNode(list);
	printf("%d\n", mid->data);
}
void TestList7()
{
	ListNode* list1 = NULL;
	PushBack(&list1, 1);
	PushBack(&list1, 3);
	PushBack(&list1, 5);
	PushBack(&list1, 7);
	PushBack(&list1, 6);
	PrintList(list1);
	ListNode* list = FindTail_k_Node(list1, 3);
	printf("%d\n",list->data);
}