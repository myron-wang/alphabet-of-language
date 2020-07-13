#ifndef LC_147_INSERT_SORT_OF_LIST_H
#define LC_147_INSERT_SORT_OF_LIST_H

#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
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
        ListNode* InsertionSortList(ListNode* head)
        {
                ListNode* dummy = new ListNode(INT_MAX);
                dummy->next = head;
                ListNode* preNode = dummy;
                while (head)
                {
                        ListNode* curNode = head;
                        head = head->next;
                        if (preNode->val <= curNode->val)
                        {
                                preNode = curNode;
                                continue;
                        }
                        preNode->next = curNode->next;
                        ListNode* p = dummy;
                        for (p = dummy; p != head; p = p->next)
                        {
                                if (p->next->val < curNode->val)
                                {
                                        continue;
                                }
                                curNode->next = p->next;
                                p->next = curNode;
                                break;
                        }
                }
                head = dummy->next;
                delete dummy;
                return head;
        }
};

//s[]是⻓⽂本，p[]是模式串，n是s的⻓度，m是p的⻓度 求模式串的Next数组

const int N = 100010;
char s[N] = { 0 };
char p[N] = { 0 };
int ne[N] = { 0 };

void KMP(void)
{
        int n = 0;
        int m = 0;
        scanf("%d%d", &n, &m);
        for (int i = 2, j = 0; i <= m; ++i)
        {
                while (j && p[i] != p[j + 1])
                {
                        j = ne[j];
                }
                if (p[i] == p[j + 1])
                {
                        j++;
                }
                ne[i] = j;
        }
        // 匹配
        for (int i = 1, j = 0; i <= n; ++i)
        {
                while (j && s[i] != p[j + 1])
                {
                        j = ne[j];
                }
                if (s[i] == p[j + 1])
                {
                        j++;
                }
                if (j == m)
                {
                        j = ne[j];
                        // 匹配成功后的逻辑
                }
        }
}

#endif