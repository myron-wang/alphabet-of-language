#ifndef LC_46_FULL_PERMUTATION_H
#define LC_46_FULL_PERMUTATION_H

#include <vector>
#include <string>
using namespace std;

/*
求输入数组的全排列问题
*/

class Solution
{
public:
        void Backtrack(vector<vector<int>>& res, vector<int>& output, int first, int len)
        {
                if (first == len)
                {
                        //emplace_back函数与push_back函数一样，但是emplace_back函数向容器中加入临时变量时，
                        //临时变量原地构造，没有赋值或移动的操作，据测试，其速度要快一倍
                        res.emplace_back(output);
                        return;
                }
                for (int i = first; i < len; ++i) {
                        swap(output[i], output[first]);
                        Backtrack(res, output, first + 1, len);
                        swap(output[i], output[first]);
                }
        }
        vector<vector<int>> Permute(vector<int>& nums)
        {
                vector<vector<int>> res;
                Backtrack(res, nums, 0, (int)nums.size());
                return res;
        }
};

void test46(void)
{
        Solution sol;
        vector<int> nums = { 3, 2, 1};
        vector<vector<int>> res = sol.Permute(nums);
        for (int i = 0; i < res.size(); ++i)
        {
                printf("第(%d)组:\n", i + 1);
                for (int j = 0; j < res[0].size(); ++j)
                {
                        printf("%d\t", res[i][j]);
                }
                printf("\n");
        }
}


#endif