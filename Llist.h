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

//����һ�����
ListNode* BuyNode(DataType x)
{
	ListNode* node = (ListNode*)malloc(sizeof(ListNode));
	node->data = x;
	node->next = NULL;
	return node;
}

//β��
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
//����һ�����
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

//��β��ͷ��ӡ������-----(�ݹ鷨)
void PrintListFromTailtoHead(ListNode* plist)
{
	ListNode* cur = plist;
	if (cur != NULL)
	{
		PrintListFromTailtoHead(cur->next);
		printf("%d->", cur->data);
	}
}

//ɾ����ͷ������ķ�β���--����pos->next����data��pos��data,Ȼ��ɾ��pos->next��㣩
void EraseNonTail(ListNode* pos)
{
	assert(pos&&pos->next);
	ListNode* next = pos->next;
	pos->data = next->data;
	pos->next = next->next;//ժ���
	free(next);
}

//����ͷ�������һ�����ǰ����һ�����
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

//������ʵ��Լɪ��
ListNode* JosepRing(ListNode* list, int k)//ɾ����K����㣬���������data�ĳ���һ������data��Ȼ��ɾ����K��������һ����㡣
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

//��ת/���õ�����
ListNode* Reverse(ListNode* list)
{
	ListNode* newlist = NULL;
	ListNode* cur = list;
	while (cur)
	{
		//ժ���
		ListNode* tmp = cur;
		cur = cur->next;
		//����--������newlistǰ����tmp��
		tmp->next = newlist;
		newlist = tmp;
	}
	return newlist;
}

//��������ð�ݣ�
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
			if (prev->data > next->data)//������������ֵ����ķ��ں�
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

//�ϲ��������������ϲ�����Ȼ����
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
	//���ҳ�����������С��һ����㣬����ժ�������������ͷ���
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
	//Ȼ��ʼβ��
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

//����������м��㣬Ҫ��ֻ�ܱ���һ������--(����ָ�뷨)
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

//������������K����㣬Ҫ��ֻ�ܱ���һ������----������ָ�뷨��
ListNode* FindTail_k_Node(ListNode* list,int K)
{
	ListNode* slow = list;
	ListNode* fast = list;
	while (--K)
	{
		if (fast == NULL)//fastΪ��˵��Kֵ���������ȡ���Kֵ��Ч
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

//��ӡ����
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