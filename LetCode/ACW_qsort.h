#ifndef ACW_QSORT_H
#define ACW_QSORT_H

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
qsort经典实现方法
*/

class Myron
{
public:
        void MyronQsort(int q[], int l, int r)
        {
                if (l >= r)
                {
                        return;
                }
                int i = l - 1;
                int j = r + 1;
                int x = q[l + r >> 1];
                while (i < j)
                {
                        do ++i; while (q[i] < x);
                        do --j; while (q[j] > x);
                        if (i < j)
                        {
                                swap(q[i], q[j]);
                        }
                }
                MyronQsort(q, l, j);
                MyronQsort(q, j + 1, r);
        }
};

void testQsort(void)
{
        int nums[8] = { 3, 4, 6, 2, 7, 3, 8, 1 };
        Myron my;
        my.MyronQsort(nums, 0, 7);
        for (int i = 0; i < 8; ++i)
        {
                printf("%d\t", nums[i]);
        }
        printf("\n");

}
#endif