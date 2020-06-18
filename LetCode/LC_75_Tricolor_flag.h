#ifndef LC_75_TRICOLOR_FLAG_H
#define LC_75_TRICOLOR_FLAG_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

/*
三色旗排序问题
*/

class Solution
{
public:
        void SortTricolorFlag(vector<int>& nums)
        {
                int p0 = 0, curr = 0;
                int p2 = nums.size() - 1;
                while (curr <= p2)
                {
                        if (nums[curr] == 0)
                        {
                                swap(nums[curr++], nums[p0++]);
                        }
                        else if (nums[curr] == 2)
                        {
                                swap(nums[curr], nums[p2--]);
                        }
                        else {
                                curr++;
                        }
                }
        }
};

void test75(void)
{
        Solution sol;
        vector<int> nums = { 2, 2, 1, 1, 0, 0, 2, 1, 0, 1 };
        sol.SortTricolorFlag(nums);
        for (int i = 0; i < nums.size(); ++i)
        {
                cout << nums[i] << endl;
        }
}
#endif