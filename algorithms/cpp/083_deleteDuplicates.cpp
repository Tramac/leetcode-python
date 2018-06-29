#include <iostream>
#include <algorithm>

using namespace std;

struct ListNode
{
    int m_nValue;
    ListNode *m_pNext;
};

ListNode* deleteDuplicates(ListNode* head)
{
    if(head == NULL)
        return NULL;
    ListNode *pNode = head;
    while(pNode != NULL)
    {
        ListNode *pNext = pNode->m_pNext;
        bool needDelete = false;
        if(pNext != NULL && pNext->m_nValue == pNode->m_nValue)
            needDelete = true;
        if(!needDelete)
        {
            pNode = pNode->m_pNext;
        }
        else
        {
            int value = pNode->m_nValue;
            ListNode *pToBeDel = pNext;
            while(pToBeDel != NULL && pToBeDel->m_nValue == value)
            {
                pNext = pToBeDel->m_pNext;

                delete pToBeDel;
                pToBeDel = NULL;

                pToBeDel = pNext;
            }
            pNode->m_pNext = pNext;
            pNode = pNext;
        }
    }
    return head;
}
