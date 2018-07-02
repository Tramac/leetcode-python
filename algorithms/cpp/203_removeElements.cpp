#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

ListNode* removeElements(ListNode* head, int val)
{
	if(head == NULL)
		return NULL;
	ListNode *pPrev = NULL;
	ListNode *pNode = head;
	ListNode *pNewHead = NULL;
	while (pNode != NULL)
	{
		ListNode *pNext = pNode->next;
		if (pNode->val == val)
		{
			delete pNode;
			pNode = NULL;
			if(pPrev != NULL)
			    pPrev->next = pNext;
			pNode = pNext;
		}
		else
		{
			if(pPrev == NULL)
			    pNewHead = pNode;
			pPrev = pNode;
			pNode = pNext;
		}
	}
	return pNewHead;
}

int main()
{
	ListNode *a1 = new ListNode(1);
	ListNode *a2 = new ListNode(2);
	ListNode *a3 = new ListNode(6);
	ListNode *a4 = new ListNode(3);
	ListNode *a5 = new ListNode(4);
	ListNode *a6 = new ListNode(5);
	ListNode *a7 = new ListNode(6);
	a1->next = a2;
	a2->next = a3;
	a3->next = a4;
	a4->next = a5;
	a5->next = a6;
	a6->next = a7;
	a7->next = NULL;
	ListNode *newHead = removeElements(a1, 6);
	return 0;
}
