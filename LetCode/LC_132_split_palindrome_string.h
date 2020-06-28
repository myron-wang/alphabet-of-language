#ifndef LC_132_SPLIT_PALINDROME_STRING_H
#define LC_132_SPLIT_PALINDROME_STRING_H
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
        int n;
        void AppendFromCenter(vector<vector<bool>>& helper, int l, int r, string s)
        {
                while (l >= 0 && r < n)
                {
                        if (s[l] == s[r])
                        {
                                helper[l][r] = true;
                        } else {
                                break;
                        }
                        l--;
                        r++;
                }
        }
        int MinCut(string s)
        {
                n = s.size();
                vector<vector<bool>> helper(n, vector<bool>(n, false));
                for (int i = 0; i < n; ++i)
                {
                        AppendFromCenter(helper, i, i, s);
                        AppendFromCenter(helper, i, i + 1, s);
                }
                vector<int> dp(n, 0);
                for (int i = 1; i < n; ++i)
                {
                        if (helper[0][i])
                        {
                                dp[i] = 0;
                        } else {
                                dp[i] = dp[i - 1] + 1;
                                for (int j = 0; j < i - 1; ++j)
                                {
                                        if (helper[j + 1][i])
                                        {
                                                dp[i] = min(dp[i], dp[j] + 1);
                                        }
                                }
                        }
                }
                return dp[n - 1];
        }
};
void test132(void)
{
        string s = "aabac";
        Solution sol;
        int result = sol.MinCut(s);
        printf("%d\n", result);
}
#endif
