#ifndef LC_31_NEXTPERMUTATION_H
#define LC_31_NEXTPERMUTATION_H
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
        void NextPermutation(vector<int>& nums)
        {
                int pos = nums.size() - 1;
                while (pos > 0 && nums[pos] <= nums[pos - 1])
                {
                        pos--;
                }
                reverse(nums.begin() + pos, nums.end());
                if (pos > 0)
                {
                        int start = pos;
                        for (; start < nums.size(); start++)
                        {
                                if (nums[start] > nums[pos - 1])
                                {
                                        swap(nums[start], nums[pos - 1]);
                                        break;
                                }
                        }
                }
        }
        void NextPermutation2(vector<int>& nums)
        {
                int pos = nums.size() - 1;
                while (pos > 0 && nums[pos] <= nums[pos - 1])
                {
                        pos--;
                }
                reverse(nums.begin() + pos, nums.end());
                if (pos > 0)
                {
                        //二分查找的方式去找到大于nums[pos - 1]的第一个数
                        auto iter = upper_bound(nums.begin() + pos, nums.end(), nums[pos - 1]);
                        swap(*iter, nums[pos - 1]);
                }
        }
};

void test31(void)
{
        vector<int> nums = { 1, 3, 2, 1 };
        Solution sol;
        sol.NextPermutation2(nums);
        for (int i = 0; i < nums.size(); ++i)
        {
                printf("%d\t", nums[i]);
        }
        printf("\n");
}
#endif