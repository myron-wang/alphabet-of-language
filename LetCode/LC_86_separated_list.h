#ifndef LC_86_SEPARATED_LIST_H
#define LC_86_SEPARATED_LIST_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
调整无序链表，使小于分隔值的节点位于链表前边，其余位于链表后边，不改变链表中值的相对位置
*/

class ListNode
{
public:
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL)
        {
        }
};

class Solution
{
public:
        ListNode* PartitionOfList(ListNode* head, int sep)
        {
                if (head == NULL) {
                        return head;
                }
                ListNode* preNode = new ListNode(0);
                ListNode* behindNode = new ListNode(0);
                ListNode* p1 = preNode;
                ListNode* p2 = behindNode;
                while (head != NULL)
                {
                        if (head->val < sep)
                        {
                                p1->next = head;
                                p1 = p1->next;
                                head = head->next;
                        }
                        else {
                                p2->next = head;
                                p2 = p2->next;
                                head = head->next;
                        }
                }
                p2->next = NULL;
                p1->next = behindNode->next;
                return preNode->next;
        }
};

#endif
