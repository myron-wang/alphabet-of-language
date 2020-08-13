#ifndef LC_24_PAIR_RESERVE_LIST_H
#define LC_24_PAIR_RESERVE_LIST_H
#include <algorithm>
#include <vector>
using namespace std;

/*
链表成对取反，用递归的方法实现
*/

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
        ListNode* SwapPairs(ListNode* head)
        {
                if (head == NULL || head->next == NULL)
                {
                        return head;
                }
                ListNode* p = head->next;
                ListNode* tmp = p->next;
                p->next = head;
                head->next = SwapPairs(tmp);
                return p;
        }
};
#endif