#ifndef LC_188_STOCKS_PROBLEM
#define LC_188_STOCKS_PROBLEM
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*

six stocks problems
base case:
dp[-1][k][0] = dp[i][0][0] = 0;
dp[-1][k][1] = dp[i][0][1] = -INT_MAX;

state transfer:
dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);

*/
class Solution
{
public:
        /* problem 1 */
        int MaxProfiles1(vector<int>& prices)
        {
                int n = prices.size();
                vector<vector<int>> dp(n, vector<int>(2, 0));
                for (int i = 0; i < n; ++i)
                {
                        if (i - 1 == -1)
                        {
                                dp[i][0] = 0;
                                dp[i][1] = -INT_MAX;
                                continue;
                        }
                        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                        dp[i][1] = max(dp[i - 1][1], - prices[i]);
                }
                return dp[n - 1][0];
        }
        int MaxProfiles1Optimization(vector<int>& prices)
        {
                int n = prices.size();
                int dp_i_0 = 0, dp_i_1 = -INT_MAX;
                for (int i = 0; i < n; ++i)
                {
                        dp_i_0 = max(dp_i_0, dp_i_1 + prices[i]);
                        dp_i_1 = max(dp_i_1, - prices[i]);
                }

                return dp_i_0;
        }
        int MaxProfilesK(vector<int>& prices)
        {
                int n = prices.size();
                int max_k = 2;
                vector<vector<vector<int>>> dp(n, vector <vector<int>>(max_k + 1, vector<int>(2, 0)));
                for (int i = 0; i < n; i++)
                {
                        for (int k = max_k; k >= 1; k--)
                        {//k应该是指使用了k次,即目前进行了k次操作
                                if (i - 1 == -1)
                                {
                                        dp[i][0][0] = 0;
                                        dp[i][0][1] = -INT_MAX;
                                        dp[i][1][0] = 0;
                                        dp[i][1][1] = -prices[i];
                                        continue;
                                }
                                dp[i][k][0] = max(dp[i - 1][k][0], dp[i - 1][k][1] + prices[i]);
                                dp[i][k][1] = max(dp[i - 1][k][1], dp[i - 1][k - 1][0] - prices[i]);
                        }
                }
                return dp[n - 1][max_k][0];

        }

        int MaxProfilesK_2(vector<int>& prices)
        {
                int	dp_i10 = 0, dp_i11 = -INT_MAX;				
                int	dp_i20 = 0, dp_i21 = -INT_MAX;				
                for (auto price : prices) 
                {
                        dp_i20 = max(dp_i20, dp_i21 + price);								
                        dp_i21 = max(dp_i21, dp_i10 - price);								
                        dp_i10 = max(dp_i10, dp_i11 + price);								
                        dp_i11 = max(dp_i11, -price);
                }				
                return	dp_i20;
        }

};

void test188(void)
{
        vector<int> prices = { 3, 5, 7, 2, 6, 8 };
        Solution sol;
        int result = sol.MaxProfilesK(prices);
        printf("%d\n", result);
}
#endif