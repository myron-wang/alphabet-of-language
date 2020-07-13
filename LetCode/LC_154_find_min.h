#ifndef LC_154_FIND_MIN_H
#define LC_154_FIND_MIN_H
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
        int FindMin(vector<int>& nums)
        {
                if (nums.size() == 0)
                {
                        return -1;
                }
                int l = 0, r = nums.size() - 1;
                int mid;
                while (l < r)
                {
                        //if (r - l == 1)
                        //{
                        //        return (nums[l] <= nums[r] ? nums[l] : nums[r]);
                        //}
                        mid = l + r >> 1;
                        if (nums[mid] > nums[r])
                        {
                                /*l = mid;*/
                                l = mid + 1;
                        } else {
                                r = mid;
                        }
                }
                //return 1;
                return nums[l];
        }
        int FindMin2(vector<int>& nums)
        {
                if (nums.size() == 0)
                {
                        return -1;
                }
                int l = 0, r = nums.size() - 1;
                int mid;
                while (l < r)
                {
                        //if (r - l == 1)
                        //{
                        //        return (nums[l] <= nums[r] ? nums[l] : nums[r]);
                        //}
                        mid = l + r >> 1;
                        if (nums[mid] > nums[r])
                        {
                                /*l = mid;*/
                                l = mid + 1;
                        }else if (nums[mid] < nums[l])
                        {
                                r = mid;
                        }else {
                                r -= 1;
                        }
                }
                //return 1;
                return nums[l];
        }
};

void test154(void)
{
        vector<int> nums = { 3, 4, 5, 1, 2 };
        //vector<int> nums = { 2, 2, 2, 1, 2, 2, 2, 2};
        Solution sol;
        int result = sol.FindMin2(nums);
        printf("%d\n", result);
}
#endif