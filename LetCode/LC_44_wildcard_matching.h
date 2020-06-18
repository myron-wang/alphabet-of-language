#ifndef LC_44_WILDCARD_MATCHING_H
#define LC_44_WILDCARD_MATCHING_H

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

/*
Õ®≈‰∑˚∆•≈‰Œ Ã‚*£ø
*/

class Solution
{
public:
        bool IsMatch(string str, string pat)
        {
                int strLen = str.size();
                int patLen = pat.size();
                vector<vector<bool>> dp(strLen + 1, vector<bool>(patLen + 1, false));
                dp[0][0] = true;

                for (int i = 1; i <= patLen; ++i)
                {
                        if (pat[i - 1] == '*' && dp[0][i - 1])
                        {
                                dp[0][i] = dp[0][i - 1];
                        }
                }
                for (int i = 1; i <= strLen; ++i)
                {
                        for (int j = 1; j <= patLen; ++j)
                        {
                                if (str[i - 1] == pat[j - 1] || pat[j - 1] == '?')
                                {
                                        dp[i][j] = dp[i - 1][j - 1];
                                }
                                else if (pat[j - 1] == '*')
                                {
                                        dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                                }
                        }
                }
                return dp[strLen][patLen];
        }
};

void test44(void)
{
        string str = "abcdefg";
        string pat = "a*b*g";
        string pat1 = "ab?de*g";
        Solution sol;
        int isTrue = sol.IsMatch(str, pat1);
        printf(" «∑Ò∆•≈‰:%d\n", isTrue);
        system("pause");
}

#endif