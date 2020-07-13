#ifndef LC_213_ROBBING_HUOSE_H
#define LC_213_ROBBING_HUOSE_H
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
        int Rob(vector<int>& nums)
        {
                int n = nums.size();
                if (n == 0)
                {
                        return 0;
                }else if (n < 4)
                {
                        return (*max_element(nums.begin(), nums.end()));
                }
                vector<vector<int>> dp(n, vector<int>(2, 0));
                dp[0][0] = 0;
                dp[0][1] = nums[0];
                dp[1][1] = nums[0];
                dp[1][0] = nums[1];
                for (int i = 2; i < n; i++)
                {
                        if (i != n - 1)
                        {
                                dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + nums[i]);
                                dp[i][1] = max(dp[i - 1][1], dp[i - 2][1] + nums[i]);
                        } else {
                                dp[i][0] = max(dp[i - 1][0], dp[i - 2][0] + nums[i]);
                                dp[i][1] = dp[i - 1][1];
                        }
                }
                return max(dp[n - 1][0], dp[n - 1][1]);
        }
};

void test213(void)
{
        vector<int> nums = { 1, 2, 3, 1 };
        Solution sol;
        int result = sol.Rob(nums);
        printf("%d\n", result);
}
#endif