#ifndef MEDIAN_OF_TWO_ARRAY_H
#define MEDIAN_OF_TWO_ARRAY_H
#include <vector>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

/*
获取两个数组的中位数
*/

class MedTwoArr
{
public:
        int MinNum(int num_a, int num_b)
        {
                return num_a < num_b ? num_a : num_b;
        }
        int GetIndexValueOfTwoArray(const vector<int>& arr_a, const vector<int>& arr_b, int index)
        {
                int len_a = arr_a.size();
                int len_b = arr_b.size();
                int idx_a = 0, idx_b = 0;
                while (true)
                {
                        if (len_a == idx_a)
                        {
                                return arr_b[idx_b + index - 1];
                        }
                        if (len_b == idx_b)
                        {
                                return arr_a[idx_a + index - 1];
                        }
                        if (index == 1)
                        {
                                return MinNum(arr_a[idx_a], arr_b[idx_b]);
                        }
                        int new_idx_a = MinNum(idx_a + index / 2 - 1, len_a - 1);
                        int new_idx_b = MinNum(idx_b + index / 2 - 1, len_b - 1);
                        if (arr_a[new_idx_a] < arr_b[new_idx_b])
                        {
                                index -= new_idx_a - idx_a + 1;
                                idx_a = new_idx_a + 1;
                        }
                        else {
                                index -= new_idx_b - idx_b + 1;
                                idx_b = new_idx_b + 1;
                        }
                }
        }

        int GetMedianOfTwoArray(const vector<int>& arr_a, const vector<int>& arr_b)
        {
                int len_a = arr_a.size();
                int len_b = arr_b.size();
                if ((len_a + len_b) % 2 == 1)
                {
                        return GetIndexValueOfTwoArray(arr_a, arr_b, (len_a + len_b + 1) / 2);
                }
                else {
                        return (GetIndexValueOfTwoArray(arr_a, arr_b, (len_a + len_b) / 2) +
                                GetIndexValueOfTwoArray(arr_a, arr_b, (len_a + len_b + 1) / 2));
                }
        }
};

void test2(void)
{
        vector<int> arr_a;
        vector<int> arr_b;
        arr_a.clear();
        arr_b.clear();
        for (int i = 2; i < 8; i++)
        {
                arr_a.push_back(i);
        }
        arr_b.push_back(1);
        MedTwoArr num;
        int median_num = num.GetMedianOfTwoArray(arr_a, arr_b);
        printf("两个数组的中位数是：%d\n", median_num);
        system("pause");
}

#endif