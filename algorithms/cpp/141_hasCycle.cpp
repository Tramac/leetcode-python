#include <iostream>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

bool hasCycle(ListNode* head)
{
	if(head == NULL)
		return false;
	ListNode *slow = head->next;
	if(slow == NULL)
		return false;
	ListNode *fast = slow -> next;
	while(slow != NULL && fast != NULL)
	{
		if(slow == fast)
			return true;
		else
		{
			slow = slow->next;
			fast = fast->next;
			if(fast-> != NULL)
				fast = fast->next;
		}
	}
	return false;
}
