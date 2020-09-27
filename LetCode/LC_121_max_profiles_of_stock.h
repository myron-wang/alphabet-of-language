#ifndef LC_121_MAX_PROFILES_OF_STOCK_H
#define LC_121_MAX_PROFILES_OF_STOCK_H

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
股票交易问题，只交易一次，先买后卖
*/

class Solution
{
public:
        int MaxProfiles(vector<int>& nums)
        {
                int res = 0;
                int buy = INT_MAX;
                for (int i = 0; i < nums.size(); ++i)
                {
                        buy = min(buy, nums[i]);
                        res = max(res, nums[i] - buy);
                }
                return res;
        }
};

void test121(void)
{
        Solution sol;
        vector<int> nums = { 2, 5, 1, 6, 4, 8 };
        int result = sol.MaxProfiles(nums);
        printf("%d", result);
}
#endif