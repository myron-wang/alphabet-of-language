#ifndef LC_120_MINIMUM_SUM_OF_TRIANGLE_H
#define LC_120_MINIMUM_SUM_OF_TRIANGLE_H

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
求取三角形中最小路径和
*/

class Solution
{
public:
        int MinimumTotal(vector<vector<int>>& triangle)
        {
                vector<int> dp(triangle.back());
                for (int i = triangle.size() - 2; i >= 0; --i)
                {
                        for (int j = 0; j <= i; ++j)
                        {
                                dp[j] = min(dp[j], dp[j + 1]) + triangle[i][j];
                        }
                }
                return dp[0];
        }
};

#endif