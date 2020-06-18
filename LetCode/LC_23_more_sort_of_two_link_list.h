#ifndef LC_23_MORE_SORT_OF_TWO_LINK_LIST_H
#define LC_23_MORE_SORT_OF_TWO_LINK_LIST_H

#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
���η���һ���ö��ֵ�˼��ȥ�������⣬˳��ϲ�K������
*/

class ListNode
{
public:
        int val;
        ListNode* next;
        ListNode(int x) : val(x), next(NULL){}
        ListNode() : val(0), next(NULL) {}
};

class Solution
{
public:
        ListNode* MergeTwoLinkList(ListNode* listA, ListNode* listB)
        {
                ListNode phead;
                ListNode* ph = &phead;
                while (listA != NULL && listB != NULL)
                {
                        if (listA->val < listB->val)
                        {
                                ph->next = listA;
                                listA = listA->next;
                        } else {
                                ph->next = listB;
                                listB = listB->next;
                        }
                        ph = ph->next;
                }
                ph->next = listA == NULL ? listB : listA;
                return phead.next;
        }
        ListNode* Merge(vector<ListNode*> &lists, int l, int r)
        {
                if (l == r)
                {
                        return lists[l];
                }
                if (l > r)
                {
                        return nullptr;
                }
                int mid = (l + r) >> 1;
                return MergeTwoLinkList(Merge(lists, l, mid), Merge(lists, mid + 1, r));
        }
        ListNode* MergeLists(vector<ListNode*> &lists)
        {
                return Merge(lists, 0, lists.size());
        }
};

#endif