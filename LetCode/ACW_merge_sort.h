#ifndef ACW_MERGE_SORT_H
#define ACW_MERGE_SORT_H

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

/* 可以用归并排序解决两个排序数组中位数问题 */
const int N = 100010;
int q[N], tmp[N];
void MergeSort(int q[], int l, int r)
{
        if (l >= r)
        {
                return;
        }
        int mid = l + r >> 1;
        MergeSort(q, l, mid);
        MergeSort(q, mid + 1, r);
        int i = l, j = mid + 1, k = 0;
        while (i <= mid && j <= r)
        {
                if (q[i] < q[j])
                {
                        tmp[k++] = q[i++];
                } else {
                        tmp[k++] = q[j++];
                }
        }
        while (i <= mid)
        {
                tmp[k++] = q[i++];
        }
        while (j <= r)
        {
                tmp[k++] = q[j++];
        }
        for (int i = l, j = 0; i <= r; i++, j++)
        {
                q[i] = tmp[j];
        }
}
#endif