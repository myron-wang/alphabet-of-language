#ifndef LC_86_SEPARATED_LIST_H
#define LC_86_SEPARATED_LIST_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
������������ʹС�ڷָ�ֵ�Ľڵ�λ������ǰ�ߣ�����λ�������ߣ����ı�������ֵ�����λ��
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
