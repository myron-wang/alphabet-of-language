#ifndef LC_123_MAX_PROFIT_OF_STOCK_III_H
#define LC_123_MAX_PROFIT_OF_STOCK_III_H

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
        int MaxProfit(vector<int>& prices)
        {
                if (prices.empty())
                {
                        return 0;
                }
                int n = prices.size();
                vector<vector<int>> g(n, vector<int>(3, 0));
                vector<vector<int>> l(n, vector<int>(3, 0));
                for (int i = 1; i < n; ++i)
                {
                        int diff = prices[i] - prices[i - 1];
                        for (int j = 1; j <= 2; ++j)
                        {
                                l[i][j] = max(g[i - 1][j - 1] + max(diff, 0), l[i - 1][j] + diff);
                                g[i][j] = max(l[i][j], g[i - 1][j - 1]);
                        }
                }
                return g[n - 1][2];
        }
};

void test123(void)
{
        vector<int> prices = { 1, 3, 2, 9 };
        Solution sol;
        int result = sol.MaxProfit(prices);
        printf("%d\n", result);
}

#endif