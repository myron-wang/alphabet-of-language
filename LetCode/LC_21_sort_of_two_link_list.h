#ifndef LC_21_SORT_OF_TWO_LINK_LIST_H
#define LC_21_SORT_OF_TWO_LINK_LIST_H

#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <algorithm>
using namespace std;
class ListNode
{
public:
        int value;
        ListNode* next;
        ListNode(int x) : value(x), next(NULL){}
};

/*
合并两个排序的链表并按升序排序
*/

class Solution
{
public:
        ListNode* GetNewLinkListOfTwoLinkList(ListNode* numA, ListNode* numB)
        {
                ListNode* phead = new ListNode(-1);
                ListNode* pre = phead;
                while (numA != NULL && numB != NULL)
                {
                        if (numA->value < numB->value)
                        {
                                pre->next = numA;
                                numA = numA->next;
                        }
                        else {
                                pre->next = numB;
                                numB = numB->next;
                        }
                        pre = pre->next;
                }
                pre->next = numA == NULL ? numB : numA;
                return phead->next;
        }
};
void test21(void)
{
        ListNode* pHeadA = new ListNode(-1);
        ListNode* pA = pHeadA;
        ListNode* pHeadB = new ListNode(-1);
        ListNode* pB = pHeadB;
        for (int i = 0; i < 10; ++i)
        {
                pA->next = new ListNode(i);
                pA = pA->next;
                if (i % 2 == 0)
                {
                        pB->next = new ListNode(i);
                        pB = pB->next;
                }
        }
        Solution sol;
        ListNode* pRet = sol.GetNewLinkListOfTwoLinkList(pHeadA->next, pHeadB->next);
        while (pRet != NULL)
        {
                printf("排序数组是：%d\n", pRet->value);
                pRet = pRet->next;
        }
        system("pause");
}
#endif