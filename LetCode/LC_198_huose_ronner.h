#ifndef LC_198_HOUSE_ROBBER_H
#define LC_198_HOUSE_ROBBER_H
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
        int rob(vector<int>& nums)
        {
                if (nums.empty())
                {
                        return 0;
                }
                int size = nums.size();
                if (size == 1)
                {
                        return nums[0];
                }
                vector<int> dp = vector<int>(size, 0);
                dp[0] = nums[0];
                dp[1] = max(nums[0], nums[1]);
                for (int i = 2; i < size; ++i)
                {
                        dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]);
                }
                return dp[size - 1];
        }
        int rob2(vector<int>& nums)
        {
                if (nums.empty()) {
                        return 0;
                }
                int size = nums.size();
                if (size == 1) {
                        return nums[0];
                }
                int first = nums[0];
                int second = max(nums[0], nums[1]);
                for (int i = 2; i < size; ++i) {
                        int tmp = second;
                        second = max(second, first + nums[i]);
                        first = tmp;
                }
                return second;
        }
};
void test198(void)
{
        vector<int> nums = { 3, 5, 2, 6, 3};
        Solution sol;
        int result = sol.rob2(nums);
        printf("%d\n", result);
}

#endif