#ifndef LC_128_LONGEST_CONSECUTIVE_H
#define LC_128_LONGEST_CONSECUTIVE_H

#include <algorithm>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
        int LongestConsecutive(vector<int>& nums)
        {
                unordered_set<int> num_set;
                for (int& num : nums)
                {
                        num_set.insert(num);
                }
                int longestStreak = 0;
                for (int& num : nums)
                {
                        if (!num_set.count(num - 1))
                        {
                                int currentNum = num;
                                int currentStreak = 1;
                                while (num_set.count(currentNum + 1))
                                {
                                        currentNum++;
                                        currentStreak++;
                                }
                                longestStreak = max(longestStreak, currentStreak);
                        }
                }
                return longestStreak;
        }
};

void test128(void)
{
        vector<int> nums = { 4, 2, 5, 7, 9, 1, 3 };
        Solution sol;
        int result = sol.LongestConsecutive(nums);
        printf("%d\n", result);
}

#endif
