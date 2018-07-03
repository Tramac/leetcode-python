#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

void deleteNode(ListNode* node)
{
	if(node == NULL)
		return;
	ListNode *pNext = node->next;
	if (pNext != NULL)
	{
		node->val = pNext->val;
		node->next = pNext->next;
		delete pNext;
		pNext = NULL;
	}
	return;
}
