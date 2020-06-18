#ifndef LC_85_MAX_RECTANGLE_H
#define LC_85_MAX_RECTANGLE_H

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
heights[i][j]代表[i, j]的高度
heights[i][j] = matrix[i][j] == '1' ? heigths[i - 1][j] + 1 : 0
dp[i][j][k]代表[i, j]为右下角，高度为k可以组成的面积
dp[i][j][k] = dp[i][j-1][k] + k
*/

class Solution
{
public:
        int MaximalRectangle(vector <vector<int>>& matrix)
        {
                int n = matrix.size();
                int m = 0;
                if (n > 0)
                {
                        m = matrix[0].size();
                }
                vector<vector<int>> heights(n + 1, vector<int>(m + 1, 0));
                vector<vector<vector<int>>> dp(n + 1, vector <vector<int>>(m + 1, vector<int>(n + 1, 0)));
                int ans = 0;
                for (int i = 1; i <= n; ++i) 
                {
                        for (int j = 1; j <= m; ++j)
                        {
                                if (matrix[i - 1][j - 1] == 0)
                                {
                                        continue;
                                }
                                heights[i][j] = heights[i - 1][j] + 1;
                                for (int k = 1; k <= heights[i][j]; ++k)
                                {
                                        dp[i][j][k] = dp[i][j - 1][k] + k;
                                        ans = max(ans, dp[i][j][k]);
                                }
                        }
                }
                return ans;
        }
};

void test85(void)
{
        vector<vector<int>> matrix(8, vector<int>(8, 0));
        Solution sol;
        for (int i = 2; i < matrix.size() - 2; ++i)
        {
                for (int j = 2; j < matrix[0].size() - 2; ++j)
                {
                        matrix[i][j] = 1;
                }
        }
        int result = sol.MaximalRectangle(matrix);
        printf("最大矩形面积是：%d\n", result);
}

#endif