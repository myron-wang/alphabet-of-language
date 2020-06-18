#ifndef JZ_QSORT_H
#define JZ_QSORT_H

#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

int RandomInRange(int start, int end)
{
        if (start < 0 || end < 0)
        {
                throw new exception("Invalid Parameter!");
        }
        if (start == end)
        {
                return start;
        }
        else if (start > end)
        {
                return rand() % (start - end + 1) + end;
        } else {
                return rand() % (end - start + 1) + start;
        }
}
void SwapNum(int& numA, int& numB)
{
        int tmp = numA;
        numA = numB;
        numB = tmp;
}

int Partition(int data[], int len, int start, int end)
{
        if (data == NULL || len <= 0 || start < 0 || end >= len)
        {
                throw new exception("Invalid Parameter!");
        }
        int index = RandomInRange(start, end);
        SwapNum(data[index], data[end]);
        int smallNum = start - 1;
        for (index = start; index < end; ++index)
        {
                if (data[index] < data[end])
                {
                        ++smallNum;
                        if (smallNum != index)
                        {
                                SwapNum(data[smallNum], data[index]);
                        }
                }
        }
        ++smallNum;
        SwapNum(data[smallNum], data[end]);
        return smallNum;
}
void QuickSort(int data[], int len, int start, int end)
{
        if (start == end)
        {
                return;
        }
        int index = Partition(data, len, start, end);
        if (index > start)
        {
                QuickSort(data, len, start, index - 1);
        }
        if (index < end)
        {
                QuickSort(data, len, index + 1, end);
        }
}
void testJZ(void)
{
        int numArr[10] = { 3, 6, 7, 8, 9, 1, 0, 4, 5, 2 };
        QuickSort(numArr, 10, 0, 9);
        for (int i = 0; i < 10; i++)
        {
                printf("%d\n", numArr[i]);
        }
}
#endif