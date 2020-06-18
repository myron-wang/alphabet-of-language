#ifndef LC_77_COMBINE_H
#define LC_77_COMBINE_H

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
        vector<vector<int>> res;
        void Backtrace(vector<int>& trace, int start, int k, int n)
        {
                if (trace.size() == k)
                {
                        res.emplace_back(trace);
                        return;
                }
                for (int i = start; i <= n; ++i)
                {
                        trace.emplace_back(i);
                        Backtrace(trace, i + 1, k, n);
                        trace.pop_back();
                }

        }

        vector<vector<int>> Combine(int n, int k)
        {
                if (n <= 0 || k <= 0)
                {
                        return res;
                }
                vector<int> trace;
                trace.clear();
                Backtrace(trace, 1, k, n);
                return res;
        }
};

void test77(void)
{
        Solution sol;
        vector<vector<int>> res = sol.Combine(4, 2);
        for (int i = 0; i < res.size(); ++i) {
                printf("ตฺ(%d)ื้:\n", i + 1);
                for (int j = 0; j < res[0].size(); ++j) {
                        printf("%d\t", res[i][j]);
                }
                printf("\n");
        }
}
#endif
