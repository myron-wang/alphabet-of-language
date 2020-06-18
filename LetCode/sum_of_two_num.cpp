#include "sum_of_two_num.h"

using namespace std;

int NumMin(int num_a, int num_b)
{
        return num_a < num_b ? num_a : num_b;
}

int NumMax(int num_a, int num_b)
{
        return num_a > num_b ? num_a : num_b;
}

int CmpTwoNum(const void* num_a, const void* num_b)
{
        return ((NumIdxVal*)num_a)->value - ((NumIdxVal*)num_b)->value;
}

int BinarySearch(const NumIdxVal* num_list, int pos, int num_size, int target)
{
        int left_idx = pos, right_idx = num_size, mid_idx = 0;
        while (left_idx < right_idx)
        {
                mid_idx = left_idx + (right_idx - 1) >> 1;
                if (num_list[mid_idx].value == target)
                {
                        return num_list[mid_idx].index;
                }
                else if (num_list[mid_idx].value > target)
                {
                        right_idx = mid_idx - 1;
                }
                else 
                {  
                        left_idx = mid_idx + 1;
                }
        }
        return -1;
}
/*
求取数组中两个数的和等于目标值的数的索引坐标
*/

int* TestSumOfTwoNumber(int* numbers, int num_len, int target, int* ret_size)
{
        if (numbers == NULL)
        {
                return NULL;
        }
        int* res = (int*)malloc(sizeof(int)* 2);
        NumIdxVal* num_list = (NumIdxVal*)malloc(sizeof(NumIdxVal)* num_len);
        for (int i = 0; i < num_len; ++i)
        {
                num_list[i].value = numbers[i];
                num_list[i].index = i;
        }
        *ret_size = 2;
        int num_mid = -1;
        qsort(num_list, num_len, sizeof(NumIdxVal), CmpTwoNum);
        for (int j = 0; j < num_len; ++j)
        {
                num_mid = BinarySearch(num_list, j + 1, num_len, target - num_list[j].value);
                if (num_mid != -1)
                {
                        res[0] = NumMin(num_list[j].index, num_mid);
                        res[1] = NumMax(num_list[j].index, num_mid);
                        break;
                }
        }
        if (num_mid == -1)
        {
                res[0] = -1;
                res[1] = -1;
        }
        free(num_list);
        return res;
}

int test(void)
{
        printf("函数开始测试！！！\n");
        int num_list[10] = { 7, 8, 1, 3, 2, 4, 6, 9, 5, 10 };
        int retsize = 0;
        int *res_list = TestSumOfTwoNumber(num_list, 10, 20, &retsize);
        for (int i = 0; i < retsize; ++i) {
                printf("符合要求的数字位置%d\n", res_list[i]);
        }
        free(res_list);
        printf("函数结束测试！！！\n");
        system("pause");
        return 0;
}