#ifndef LC_164_MAXIMUM_SPACING_H
#define LC_164_MAXIMUM_SPACING_H
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

class Solution
{
public:
        /* 快排时间复杂度为nlogn */
        int MaximumGap(vector<int>& nums)
        {
                if (nums.size() < 2)
                {
                        return 0;
                }
                sort(nums.begin(), nums.end());
                int maxGap = 0;
                for (int i = 0; i < nums.size() - 1; ++i)
                {
                        maxGap = max(nums[i + 1] - nums[i], maxGap);
                }
                return maxGap;
        }
        /* 基数排序时间复杂度为k*n */
        int MaximumGap2(vector<int>& nums)
        {
                if (nums.size() < 2)
                {
                        return 0;
                }
                int maxVal = *max_element(nums.begin(), nums.end());
                int expr = 1;
                int radix = 10;
                vector<int> aux(nums.size());
                while (maxVal / expr > 0)
                {
                        vector<int> count(radix, 0);

                        for (int i = 0; i < nums.size(); ++i)
                        {
                                count[(nums[i] / expr) % 10]++;
                        }
                        for (int i = 1; i < count.size(); ++i)
                        {
                                count[i] += count[i - 1];
                        }
                        for (int i = nums.size() - 1; i >= 0; --i)
                        {
                                aux[--count[(nums[i] / expr) % 10]] = nums[i];
                        }
                        for (int i = 0; i < nums.size(); i++)
                        {
                                nums[i] = aux[i];
                        }
                        expr *= 10;
                }
                int maxGap = 0;
                for (int i = 0; i < nums.size() - 1; ++i) {
                        maxGap = max(nums[i + 1] - nums[i], maxGap);
                }
                return maxGap;
        }
};
#endif