#ifndef LC_174_DUNGEON_GAME_H
#define LC_174_DUNGEON_GAME_H
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
计算屠龙勇士营救公主最小需要的血条值，正向dp不好算，可以反向dp
*/

class Solution
{
public:
        int CalculateMinimumHP(vector<vector<int>>& dungeon)
        {
                int n = dungeon.size(), m = dungeon[0].size();
                vector<vector<int>> dp(n + 1, vector<int>(m + 1, INT_MAX));
                dp[n][m - 1] = 1;
                dp[n - 1][m] = 1;//血量至少需要一点
                for (int i = n - 1; i >= 0; --i)
                {
                        for (int j = m - 1; j >= 0; --j)
                        {
                                int minHP = min(dp[i + 1][j], dp[i][j + 1]);
                                dp[i][j] = max(1, minHP - dungeon[i][j]);
                        }
                }
                return dp[0][0];
        }
};
#endif