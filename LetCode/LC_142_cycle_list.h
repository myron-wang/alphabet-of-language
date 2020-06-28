#ifndef LC_142_CYCLE_LIST_H
#define LC_142_CYCLE_LIST_H

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
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
        ListNode* DetectCycle(ListNode* head)
        {
                ListNode* slow = head;
                ListNode* fast = head;
                while (fast != NULL && fast->next != NULL)
                {
                        slow = slow->next;
                        fast = fast->next->next;
                        if (slow == fast)
                        {
                                slow = head;
                                while (slow != fast)
                                {
                                        slow = slow->next;
                                        fast = fast->next;
                                }
                                return fast;
                        }
                }
                return NULL;
        }
};
#endif