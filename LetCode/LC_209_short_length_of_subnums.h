#ifndef LC_209_SHORT_LENGTH_OF_SUBNUMS_H
#define LC_209_SHORT_LENGTH_OF_SUBNUMS_H
#include <vector>
#include <algorithm>
using namespace std;
/*
双指针算法+滑动窗口算法
*/
class Solution
{
public:
        int MinSubArrayLen(int s, vector<int>& nums)
        {
                int n = nums.size();
                if (n == 0)
                {
                        return 0;
                }
                int ans = INT_MAX;
                int start = 0, end = 0;
                int sum = 0;
                while (end < n)
                {
                        sum += nums[end];
                        while (sum >= s)
                        {
                                ans = min(ans, end - start + 1);
                                sum -= nums[start];
                                start++;
                        }
                        end++;
                }
                return ans == INT_MAX ? 0 : ans;
        }
};
void test209(void)
{
        vector<int> nums = { 2, 3, 1, 2, 4, 3 };
        int s = 7;
        Solution sol;
        int result = sol.MinSubArrayLen(s, nums);
        printf("%d\n", result);
}
#endif