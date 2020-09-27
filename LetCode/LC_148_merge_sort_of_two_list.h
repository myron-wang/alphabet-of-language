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
��O(nlogn)��ʱ�临�Ӷ��¶�����������򣬴˺��������ù鲢����ĵݹ��ȥ����
�˴�ʹ�õ��ǹ鲢�����ѭ����
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