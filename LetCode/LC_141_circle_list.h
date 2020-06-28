#ifndef LC_141_CIRCLE_LIST_H
#define LC_141_CIRCLE_LIST_H

#include <algorithm>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

struct ListNode
{
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL)
        {
        }
};

class Solution
{
public:
        bool HasCycle(ListNode* head)
        {
                unordered_set<ListNode*> nodes;
                while (head)
                {
                        if (nodes.count(head))
                        {
                                return true;
                        }
                        nodes.insert(head);
                        head = head->next;
                }
                return false;
        }

        bool HasCycle2(ListNode* head)
        {
                if (head == NULL)
                {
                        return false;
                }
                ListNode* tmp = head->next;
                while (tmp)
                {
                        if (head = tmp)
                        {
                                return true;
                        }
                        head = head->next;
                        tmp = tmp->next;
                        if (tmp == NULL)
                        {
                                return false;
                        }
                        tmp = tmp->next;
                }
                return false;
        }

};

void test141(void)
{
        ListNode* head = new ListNode(0);
        ListNode* tmp = head;
        for (int i = 0; i < 6; ++i)
        {
                tmp->next = new ListNode(i);
                tmp = tmp->next;
        }
        tmp->next = head->next->next;
        Solution sol;
        bool result = sol.HasCycle2(head);
        printf("%d\n", result);
}
#endif