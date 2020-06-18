#ifndef LC_25_REVERSE_K_OF_LINK_LIST_H
#define LC_25_REVERSE_K_OF_LINK_LIST_H

#include <string>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

class ListNode
{
public:
        int val;
        ListNode* next;
        ListNode() : val(0), next(NULL) {}
        ListNode(int x) : val(x), next(NULL){}
};

/*
将链表节点以k长度翻转
*/

class Solution
{
public:
        pair<ListNode*, ListNode*> ReverseLinkList(ListNode* head, ListNode* tail)
        {
                ListNode* prev = tail->next; //prev指上一个
                ListNode* p = head;
                while (prev != tail)
                {
                        ListNode* next_tmp = p->next;
                        p->next = prev;
                        prev = p;
                        p = next_tmp;
                }
                return{ tail, head };
        }
        ListNode* ReserveKGroup(ListNode* head, int k)
        {
                ListNode* hair = new ListNode(0);
                hair->next = head;
                ListNode* pre = hair;
                while (head)
                {
                        ListNode* tail = pre;
                        for (int i = 0; i < k; ++i)
                        {
                                tail = tail->next;
                                if (!tail)
                                {
                                        return hair->next;
                                }
                        }
                        ListNode* next_tmp = tail->next;
                        pair<ListNode*, ListNode*> result = ReverseLinkList(head, tail);
                        head = result.first;
                        tail = result.second;
                        pre->next = head;
                        tail->next = next_tmp;
                        pre = tail;
                        head = tail->next;
                }
                return hair->next;
        }
};

void test25(void)
{
        ListNode* head = new ListNode(0);
        ListNode* p = head;
        for (int i = 0; i < 32; ++i)
        {
                p->next = new ListNode(i);
                p = p->next;
        }
        Solution sol;
        ListNode* result = sol.ReserveKGroup(head->next, 7);
        for (int j = 0; j < 32; ++j)
        {
                printf("打印翻转部分值的节点值：%d\n", result->val);
                result = result->next;
        }
        system("pause");
}
#endif
