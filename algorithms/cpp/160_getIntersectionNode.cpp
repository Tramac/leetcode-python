#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x): val(x), next(NULL) {}
};

ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
{
	if(headA == NULL || headB == NULL)
		return NULL;
	ListNode *node = headA;
	int lengthA = 0;
	while(node != NULL)
	{
		lengthA++;
		node = node->next;
	}
	node = headB;
	int lengthB = 0;
	while(node != NULL)
	{
		lengthB++;
		node = node->next;
	}
	int lengthdiff = lengthA - lengthB;
	ListNode *nodeLong = headA;
	ListNode *nodeShort = headB;
	if(lengthdiff < 0)
	{
		lengthdiff = -lengthdiff;
		nodeLong = headB;
		nodeShort = headA;
	}
	for (int i = 0; i < lengthdiff; ++i)
		nodeLong = nodeLong->next;
	while(nodeLong != NULL && nodeShort != NULL)
	{
		if(nodeLong == nodeShort)
			return nodeLong;
		else
		{
			nodeLong = nodeLong->next;
			nodeShort = nodeShort->next;
		}
	}
	return NULL;
}
