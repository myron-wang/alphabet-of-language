#include "sum_of_two_num.h"

using namespace std;

/* 求解两数之和等于目标值，返回数字索引*/

int CompareVal(const void* num_a, const void* num_b)
{
        return ((NumIdxVal*)num_a)->value - ((NumIdxVal*)num_b)->value;
}

int BinarySearch(NumIdxVal* nums, int pos, int num_size, int target)
{
        while (pos < num_size) 
        {
                int mid = pos + num_size - 1 >> 1;
                if (nums[mid].value == target)
                {
                        return nums[mid].index;
                }
                else if (nums[mid].value > target)
                {
                        num_size = mid - 1;
                } else {
                        pos = mid + 1;
                }
        }
        return -1;
}

int* TestSumOfTwoNumber(int* numbers, int num_len, int target, int* res_size)
{
        if (numbers == NULL) {
                return NULL;
        }
        int* res = (int*)malloc(sizeof(int)* 2);
        NumIdxVal* num_list = (NumIdxVal*)malloc(sizeof(NumIdxVal)* num_len);
        for (int i = 0; i < num_len; ++i) {
                num_list[i].value = numbers[i];
                num_list[i].index = i;
        }
        *res_size = 2;
        int num_mid = -1;
        qsort(num_list, num_len, sizeof(NumIdxVal), CompareVal);
        for (int j = 0; j < num_len; ++j) {
                num_mid = BinarySearch(num_list, j + 1, num_len, target - num_list[j].value);
                if (num_mid != -1)
                {
                        res[0] = min(num_mid, num_list[j].index);
                        res[1] = max(num_mid, num_list[j].index);
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
        int *res_list = TestSumOfTwoNumber(num_list, 10, 10, &retsize);
        for (int i = 0; i < retsize; ++i) {
                printf("符合要求的数字位置%d\n", res_list[i]);
        }
        free(res_list);
        printf("函数结束测试！！！\n");
        system("pause");
        return 0;
}