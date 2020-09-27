#ifndef LC_90_SUBSET_H
#define LC_90_SUBSET_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
�����к����ظ�Ԫ�أ����ظ����Ӽ�����
*/

class Solution
{
public:
        vector<vector<int>> res;
        void Subset(vector<int> &nums, int start, vector<int> &temp)
        {
                res.emplace_back(temp);
                for (int i = start; i < nums.size(); ++i)
                {
                        if (i > start && nums[i] == nums[i - 1])
                        {//������Ȼ���޳�ͬһ��ѭ���µ��ظ���
                                continue;
                        }
                        temp.emplace_back(nums[i]);
                        Subset(nums, i + 1, temp);
                        temp.pop_back();
                }
        }
        vector<vector<int>> SubsetNoDuplicate(vector<int> &nums)
        {
                vector<int> temp;
                sort(nums.begin(), nums.end());
                Subset(nums, 0, temp);
                return res;
        }
};

/*
���üӼ��˳����ӷ�
*/
int SumOfBitOperation(int numA, int numB)
{
        int sum = 0;
        int carry = 0;
        do 
        {
                sum = numA ^ numB;
                carry = (numA & numB) << 1;
                numA = sum;
                numB = carry;
        } while (numB > 0);
        return sum; // return numA;
}

void test90(void)
{
        vector<int> nums = { 1, 2, 2 };
        Solution sol;
        vector<vector<int>> result = sol.SubsetNoDuplicate(nums);
        for (int i = 0; i < result.size(); ++i)
        {
                for (vector<int> ::iterator iter = result[i].begin(); iter != result[i].end(); ++iter)
                {
                        printf("%d\t", *iter);
                }
                printf("\n");
        }
        int result0 = SumOfBitOperation(4, 9);
        printf("����֮�ͣ�%d\n", result0);
}

#endif
