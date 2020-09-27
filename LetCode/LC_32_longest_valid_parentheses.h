#ifndef LC_32_LONGEST_VALID_PARENTHESES_H
#define LC_32_LONGEST_VALID_PARENTHESES_H
#include <vector>
#include <algorithm>
using namespace std;

/*
获取最长的有效括号对，利用dp求解
*/
class Solution
{
public:
        int LongestValidParentheses(string s)
        {
                int maxans = 0;
                int n = s.length();
                vector<int> dp(n, 0);
                for (int i = 1; i < n; i++)
                {
                        if (s[i] == ')')
                        {
                                if (s[i - 1] == '(')
                                {
                                        dp[i] = (i >= 2 ? dp[i - 2] : 0) + 2;
                                }else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '(')
                                {
                                        dp[i] = dp[i - 1] + ((i - dp[i - 1]) >= 2 ? dp[i - dp[i - 1] - 2] : 0) + 2;
                                }
                                maxans = max(maxans, dp[i]);
                        }
                }
                return maxans;
        }
};
void test32(void)
{
        string str = ")((())(()(";
        Solution sol;
        int result = sol.LongestValidParentheses(str);
        printf("%d\n", result);
}
#endif