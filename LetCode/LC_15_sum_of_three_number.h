#ifndef LC_15_SUM_OF_THREE_NUMBER_H
#define LC_15_SUM_OF_THREE_NUMBER_H

#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_set>
#include <algorithm>
using namespace std;

/*
求三个数字之和为零
*/
class Solution
{
public:
        vector<vector<int>> GetListOfThreeNumber(vector<int> numList)
        {
                vector<vector<int>> retList;
                retList.clear();
                sort(numList.begin(), numList.end());
                int numLen = numList.size();
                if (numLen < 3)
                {
                        return retList;
                }
                vector<int> mid(3, 0); //初始化为3个值为0的int
                int last = -INT_MAX;
                for (int i = 0; i < numLen - 2; ++i)
                {
                        if (last != numList[i])
                        {
                                last = numList[i];
                                unordered_set<int> visited;
                                int goal = -numList[i], left = i + 1, right = numLen - 1;
                                mid[0] = numList[i];
                                while (left < right)
                                {
                                        if (numList[left] + numList[right] == goal)
                                        {
                                                if (!visited.count(numList[left]))
                                                {
                                                        visited.insert(numList[left]);
                                                        mid[1] = numList[left];
                                                        mid[2] = numList[right];
                                                        retList.push_back(mid);
                                                }
                                                left++;
                                                right--;
                                        }
                                        else if (numList[left] + numList[right] < goal)
                                        {
                                                left++;
                                        }
                                        else {
                                                right--;
                                        }
                                }
                        }
                }
                return retList;
        }
};

void test15(void)
{
        vector<int> numList = { 1, 3, 6, 8, 0, -3, -5, -6, -9, 3, -4, -2, -1 };
        Solution sol;
        vector<vector<int>> result = sol.GetListOfThreeNumber(numList);
        for (int i = 0; i < result.size(); ++i)
        {
                printf("The %d group three number is:", i);
                for (int j = 0; j < 3; ++j)
                {
                        printf(" %d", result[i][j]);
                }
                printf("\n");
        }
}
#endif