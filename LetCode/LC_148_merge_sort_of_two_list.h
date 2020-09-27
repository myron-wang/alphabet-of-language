#ifndef LC_148_MERGE_SORT_OG_TWO_LIST_H
#define LC_148_MERGE_SORT_OG_TWO_LIST_H

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

struct ListNode
{
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL)
        {
        }
};

/*
在O(nlogn)的时间复杂度下对链表进行排序，此函数可以用归并排序的递归版去处理
此处使用的是归并排序的循环版
*/

class Solution
{
public:
        ListNode* Cut(ListNode* head, int n)
        {
                auto p = head;
                while (--n && p)
                {
                        p = p->next;
                }
                if (!p)
                {
                        return nullptr;
                }
                auto next = p->next;
                p->next = nullptr;
                return next;
        }
        ListNode* Merge(ListNode* l1, ListNode* l2)
        {
                ListNode* dummyHead = new ListNode(0);
                auto p = dummyHead;
                while (l1 && l2)
                {
                        if (l1->val < l2->val)
                        {
                                p->next = l1;
                                p = l1;
                                l1 = l1->next;
                        } else {
                                p->next = l2;
                                p = l2;
                                l2 = l2->next;
                        }
                }
                p->next = l1 ? l1 : l2;
                p = dummyHead->next;
                delete dummyHead;
                return p;
        }
        ListNode* SortList(ListNode* head)
        {
                ListNode* dummyHead = new ListNode(0);
                dummyHead->next = head;
                auto p = head;
                int len = 0;
                while (p)
                {
                        ++len;
                        p = p->next;
                }

                for (int size = 1; size < len; size <<= 1)
                {
                        auto cur = dummyHead->next;
                        auto tail = dummyHead;
                        while (cur)
                        {
                                auto left = cur;
                                auto right = Cut(left, size);
                                cur = Cut(right, size);
                                tail->next = Merge(left, right);
                                while (tail->next)
                                {
                                        tail = tail->next;
                                }
                        }
                }
                p = dummyHead->next;
                delete dummyHead;
                return p;
        }
};
#endif