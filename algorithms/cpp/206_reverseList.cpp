#include <iostream>

using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

ListNode* reverseList(ListNode* head)
{
	if(head == NULL)
		return NULL;
	if(head->next == NULL)
		return head;
	ListNode *reverseHead = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return reverseHead;
}
