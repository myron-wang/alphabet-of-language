#ifndef LC_152_PRODUCT_MAXIMUM_SUBARRAY_H
#define LC_152_PRODUCT_MAXIMUM_SUBARRAY_H

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

/*
找出乘积最大的连续子数组子数组
*/

class Solution
{
public:
        int MaxProduct(vector<int>& nums)
        {
                vector<int> maxF(nums);
                vector<int> minF(nums);
                for (int i = 1; i < nums.size(); ++i)
                {
                        maxF[i] = max(maxF[i - 1] * nums[i], max(minF[i - 1] * nums[i], nums[i]));
                        minF[i] = min(maxF[i - 1] * nums[i], min(minF[i - 1] * nums[i], nums[i]));
                }
                return *max_element(maxF.begin(), maxF.end());
        }
        int MaxProduct2(vector<int>& nums)
        {
                int res = nums[0], minF2 = nums[0], maxF2 = nums[0];
                for (int i = 1; i < nums.size(); ++i)
                {
                        int maxF = maxF2, minF = minF2;
                        maxF2 = max(maxF * nums[i], max(nums[i], minF * nums[i]));
                        minF2 = min(maxF * nums[i], min(nums[i], minF * nums[i]));
                        res = max(res, maxF);
                }
                return res;
        }
};
void test152(void)
{
        vector<int> nums = { 3, 9, -3, -4, 6, -2 };
        Solution sol;
        int result = sol.MaxProduct2(nums);
        printf("%d\n", result);
}
#endif