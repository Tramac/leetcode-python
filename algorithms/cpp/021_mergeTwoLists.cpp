#include <iostream>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
};

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2)
{
    if(l1 == NULL)
        return l2;
    if(l2 == NULL)
        return l1;
    ListNode *pMergedHead = NULL;
    if(l1->m_nValue <= l2->m_nValue)
    {
        pMergedHead = l1;
        pMergedHead->m_pNext = mergeTwoLists(l1->m_pNext, l2);
    }
    else
    {
        pMergedHead = l2;
        pMergedHead->m_pNext = mergeTwoLists(l1, l2->m_pNext);
    }
    return pMergedHead;
}
