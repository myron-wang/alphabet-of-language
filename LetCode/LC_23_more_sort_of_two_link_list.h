#ifndef LC_23_MORE_SORT_OF_TWO_LINK_LIST_H
#define LC_23_MORE_SORT_OF_TWO_LINK_LIST_H

#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;
/*
分治法：一般用二分的思想去处理问题，顺序合并K个链表，其实是归并排序的思想
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
struct Status
{
        int val;
        ListNode* ptr;
        bool operator < (const Status &rhs)const
        {//这样写是为了将优先堆的大顶堆改为小顶堆
                return val > rhs.val;
        }
};

/*
此方法是利用小顶堆去比较单个链表头，不停地出堆和入堆
*/

class Solution1
{
public:
        priority_queue <Status> q; //默认大顶堆
        ListNode* MergeKList(vector<ListNode*>& lists)
        {
                for (auto node : lists)
                {
                        if (node)
                        {
                                q.push({ node->val, node });
                        }
                }
                ListNode head, *tail = &head;
                while (!q.empty())
                {
                        auto f = q.top();
                        q.pop();
                        tail->next = f.ptr;
                        tail = tail->next;
                        if (f.ptr->next)
                        {
                                q.push({ f.ptr->next->val, f.ptr->next });
                        }
                }
                return head.next;
        }
};

#endif