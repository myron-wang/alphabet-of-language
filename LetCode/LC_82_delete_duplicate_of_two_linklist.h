#ifndef LC_82_DELETE_DUPLICATES_OF_TWO_LINKLIST
#define LC_82_DELETE_DUPLICATES_OF_TWO_LINKLIST

#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*
删除链表中相同节点，即只要有相同的把所有相同的全删掉
*/

class ListNode
{
public:
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL)
        {

        }

        ListNode* DeleteDuplicates(ListNode* head)
        {
                ListNode* pre = new ListNode(0);
                pre->next = head;
                ListNode* left = pre;
                ListNode* right = pre;
                head = pre;
                while (pre->next != NULL)
                {
                        left = pre->next;
                        right = pre->next;
                        while (right->next && right->next->val == left->val)
                        {
                                right = right->next;
                        }
                        if (left == right)
                        {
                                pre = pre->next;
                        }
                        else {
                                pre->next = right->next;
                                while (left != right)
                                {
                                        ListNode* tmp = left;
                                        left = left->next;
                                        delete tmp;
                                }
                                delete left;
                        }
                }
                return head->next;
        }
};

#endif