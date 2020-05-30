#ifndef SUM_OF_TWO_LIST_NODE_H
#define SUM_OF_TWO_LIST_NODE_H

#include <stdlib.h>
#include <stdio.h>
using namespace std;

class ListNode
{
public:
        int value;
        ListNode* next;
        ListNode(int x) : value(x), next(NULL) {}
};
ListNode* GetSumOfTwoListNode(ListNode* node_a, ListNode* node_b);
void test(void);

#endif