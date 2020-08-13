#ifndef LC_16_NEAREST_TARGET_OF_THREE_NUMBER_H
#define LC_16_NEAREST_TARGET_OF_THREE_NUMBER_H
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;
/*
双指针算法，两边向中间逼近
*/
class Solution
{
public:
        int ThreeSumClosest(vector<int>& nums, int target)
        {
                sort(nums.begin(), nums.end());
                int n = nums.size();
                int best = 1e7;
                auto update = [&](int cur) {
                        if (abs(cur - target) < abs(best - target))
                        {
                                best = cur;
                        }
                };
                for (int i = 0; i < n; ++i)
                {
                        if (i > 0 && nums[i] == nums[i - 1])
                        {
                                continue;
                        }
                        int l = i + 1, r = n - 1;
                        while (l < r)
                        {
                                int sum = nums[i] + nums[l] + nums[r];
                                if (sum == target)
                                {
                                        return target;
                                }
                                update(sum);
                                if (sum > target)
                                {
                                        int r0 = r - 1;
                                        while (l < r0 && nums[r0] == nums[r])
                                        {
                                                --r0;
                                        }
                                        r = r0;
                                } else {
                                        int l0 = l + 1;
                                        while (l0 < r && nums[l0] == nums[l])
                                        {
                                                ++l0;
                                        }
                                        l = l0;
                                }
                        }
                }
                return best;
        }
};

void test16(void)
{
        vector<int> nums = { -1, 2, 1, -4 };
        Solution sol;
        int result = sol.ThreeSumClosest(nums, 1);
        printf("%d\n", result);
}
#endif