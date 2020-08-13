#ifndef LC_64_SHORTEST_SUM_OF_PATH_H
#define LC_64_SHORTEST_SUM_OF_PATH_H

#include <vector>
#include <string>
#include <algorithm>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
using namespace std;

//dynamic programming

/*
动态规划解决最短路径和问题
dp[i][j] += min(dp[i-1][j], dp[i][j-1])  + 特判边界条件
*/

class Solution
{
public:
        int MinPathSum(vector<vector<int>>& grid)
        {
                int row = grid.size();
                int col = grid[0].size();
                for (int i = 0; i < row; ++i)
                {
                        for (int j = 0; j < col; ++j)
                        {
                                if (i == 0 && j !=0)
                                {
                                        grid[i][j] += grid[i][j - 1];
                                }
                                if (j == 0 && i != 0)
                                {
                                        grid[i][j] += grid[i - 1][j];
                                }
                                if (i != 0 && j != 0)
                                {
                                        grid[i][j] += grid[i][j - 1] > grid[i - 1][j] ? grid[i - 1][j] : grid[i][j - 1];
                                }
                        }
                }
                return grid[row - 1][col - 1];
        }
};

void test64(void)
{
        Solution sol;
        vector<vector<int>> grid(4, vector<int>(3, 0));
        for (int i = 0; i < grid.size(); ++i)
        {
                for (int j = 0; j < grid[0].size(); ++j)
                {
                        grid[i][j] = i + j;
                }
        }
        int result = sol.MinPathSum(grid);
        cout << result << endl;
}

#endif