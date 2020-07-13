#ifndef LC_203_REMOVE_LIST_NODE_H
#define LC_203_REMOVE_LIST_NODE_H
#include <vector>
#include <string>
#include <algorithm>
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
        ListNode* RemoveListNode(ListNode* head, int val)
        {
                ListNode* label = new ListNode(0);
                label->next = head;
                ListNode* pre = label;
                ListNode* cur = head;
                ListNode* toDelete = NULL;
                while (cur != NULL)
                {
                        if (cur->val == val)
                        {
                                pre->next = cur->next;
                                toDelete = cur;
                        } else {
                                pre = cur;
                        }
                        cur = cur->next;

                        if (toDelete != NULL)
                        {
                                delete toDelete;
                                toDelete = NULL;
                        }
                }
                ListNode* ret = label->next;
                delete label;
                return ret;
        }

};
#endif