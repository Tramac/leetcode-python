#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

bool isPalindrome(ListNode* head)
{
	if(head == NULL)
		return true;
	ListNode *pNode = head;
	vector<int> nodes;
	while(pNode != NULL)
	{
		nodes.push_back(pNode->val);
		pNode = pNode->next;
	}
	reverse(nodes.begin(), nodes.end());
	pNode = head;
	int i = 0;
	while (pNode != NULL)
	{
		if(pNode->val != nodes[i])
			return false;
		pNode = pNode->next;
		i++;
	}
	return true;
}
