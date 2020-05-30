#include "sum_of_two_list_node.h"

/*
获得两个用链表表示的数值之和，返回一个链表表示的数值
*/

ListNode* GetSumOfTwoListNode(ListNode* node_a, ListNode* node_b)
{
        int len_a = 1;
        int len_b = 1;
        ListNode* temp_a = node_a;
        ListNode* temp_b = node_b;
        while (temp_a->next != NULL)
        {
                ++len_a;
                temp_a = temp_a->next;
        }
        while (temp_b->next != NULL)
        {
                ++len_b;
                temp_b = temp_b->next;
        }
        if (len_a > len_b)
        {
                for (int i = 1; i <= len_a - len_b; ++i)
                {
                        temp_b->next = new ListNode(0);
                        temp_b = temp_b->next;
                }
        }
        else {
                for (int j = 1; j <= len_b - len_a; ++j)
                {
                        temp_a->next = new ListNode(0);
                        temp_a = temp_a->next;
                }
        }
        temp_a = node_a;
        temp_b = node_b;
        int carry = 0;
        int sum = 0;
        ListNode* node_c = new ListNode(-1);
        ListNode* temp_c = node_c;
        while (temp_a != NULL && temp_b != NULL)
        {
                sum = carry + temp_a->value + temp_b->value;
                temp_c->next = new ListNode(sum % 10);
                carry = sum >= 10 ? 1 : 0;
                temp_a = temp_a->next;
                temp_b = temp_b->next;
                temp_c = temp_c->next;
        }
        if (carry == 1)
        {
                temp_c->next = new ListNode(1);
        }
        return node_c->next;
}

void test(void)
{
        ListNode* node_a = new ListNode(-1);
        ListNode* node_b = new ListNode(-1);
        ListNode* temp_a = node_a;
        ListNode* temp_b = node_b;
        for (int i = 0; i < 10; ++i) 
        {
                temp_a->next = new ListNode(i);
                temp_b->next = new ListNode(i);
                temp_a = temp_a->next;
                temp_b = temp_b->next;
                printf("temp_a->next is %d, temp_b->next is %d.\n", temp_a->value, temp_b->value);
        }
        ListNode* node_c = GetSumOfTwoListNode(node_a->next, node_b->next);
        while (node_c != NULL)
        {
                printf("node_c is %d\n", node_c->value);
                node_c = node_c->next;
        }
        system("pause");
}