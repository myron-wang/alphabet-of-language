#ifndef LC_22_PAIR_OF_BRACKETS_H
#define LC_22_PAIR_OF_BRACKETS_H

#include <string>
#include <algorithm>
#include <vector>
using namespace std;
/*
采用回溯法递归调用生成想要的括号对
*/

class Solution
{
public:
        void brackets(vector<string>& ans, string& current, int open, int close, int n)
        {
                if (current.size() == 2 * n)
                {
                        ans.push_back(current);
                        return;
                }
                if (open < n)
                {
                        current.push_back('(');
                        brackets(ans, current, open + 1, close, n);
                        current.pop_back();
                }
                if (close < open)
                {
                        current.push_back(')');
                        brackets(ans, current, open, close + 1, n);
                        current.pop_back();
                }
        }
        vector<string> GeneratorPairOfBrackets(int n)
        {
                vector<string> result;
                string current;
                brackets(result, current, 0, 0, n);
                return result;
        }

};

void test22(void)
{
        Solution sol;
        vector<string> result = sol.GeneratorPairOfBrackets(4);
        int len = result.size();
        for (int i = 0; i < len; ++i)
        {
                printf("打印生成的括号对(%d)：%s\n", i, result[i].c_str());
        }
}

#endif
