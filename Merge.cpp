/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
{
	typedef ListNode Node;
	if (pHead1 == NULL)
		return pHead2;
	if (pHead2 == NULL)
		return pHead1;
	Node* head = NULL;
	head = pHead1;
	pHead1 = pHead1->next;
	if (head->val>pHead2->val)
	{
		head = pHead2;
		pHead2 = pHead2->next;
	}
	Node* tail = head;
	while (pHead1&&pHead2)
	{
		if (pHead1->val > pHead2->val)
		{
			tail->next = pHead2;
			pHead2 = pHead2->next;
			tail = tail->next;
		}
		else{
			tail->next = pHead1;
			pHead1 = pHead1->next;
			tail = tail->next;
		}
	}
	if (pHead1 == NULL)
		tail->next = pHead2;
	else
		tail->next = pHead1;
	return head;
}