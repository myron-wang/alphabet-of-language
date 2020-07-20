#ifndef LC_10_REGULAR_EXPRESSION_H
#define LC_10_REGULAR_EXPRESSION_H
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
class Solution
{
public:
        bool IsMatch(string s, string p)
        {
                int m = s.size();
                int n = p.size();
                auto matches = [&](int i, int j) {
                        if (i == 0)
                        {
                                return false;
                        }
                        if (p[j - 1] == '.')
                        {
                                return true;
                        }
                        return s[i - 1] == p[j - 1];
                };
                vector<vector<int>> f(m + 1, vector<int>(n + 1));
                f[0][0] = true;
                for (int i = 0; i <= m; ++i) {
                        for (int j = 1; j <= n; ++j)
                        {
                                if (p[j - 1] == '*')
                                {
                                        f[i][j] |= f[i][j - 2];
                                        if (matches(i, j -1))
                                        {
                                                f[i][j] |= f[i - 1][j];
                                        }
                                } else {
                                        if (matches(i, j))
                                        {
                                                f[i][j] |= f[i - 1][j - 1];
                                        }
                                }
                                
                        }
                }
                return f[m][n];
        }

};

void test10(void)
{
        string s = "aab";
        string p = "c*a*b";
        Solution sol;
        int result = sol.IsMatch(s, p);
        printf("%d\n", result);
}
#endif