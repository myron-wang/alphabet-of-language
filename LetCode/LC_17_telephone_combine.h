#ifndef LC_17_TELEPHONE_COMBINE_H
#define LC_17_TELEPHONE_COMBINE_H
#include <vector>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
using namespace std;
class Solution
{
public:
        vector<string> ans;
        string current;
        void DFS(int index, string digits, map<char, string>& M)
        {
                if (index == digits.size())
                {
                        ans.push_back(current);
                        return;
                }
                for (int i = 0; i < M[digits[index]].size(); ++ i)
                {
                        current.push_back(M[digits[index]][i]);
                        DFS(index + 1, digits, M);
                        current.pop_back();
                }
        }
        vector<string> LetterCombinations(string digits)
        {
                map<char, string> M = { { '2', "abc" }, { '3', "def" }, { '4', "ghi" }, { '5', "jkl" },
                { '6', "mno" }, { '7', "pqrs" }, { '8', "tuv" }, { '9', "wxyz" } };
                if (digits.size() == 0)
                {
                        return ans;
                }
                DFS(0, digits, M);
                return ans;
        }
};

void test17(void)
{
        string nums = "23";
        Solution sol;
        vector<string> result = sol.LetterCombinations(nums);
        for (int i = 0; i < result.size(); ++i)
        {
                cout << result[i] << endl;
        }
        
}
#endif