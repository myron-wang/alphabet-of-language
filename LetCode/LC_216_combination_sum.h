#ifndef LC_216_COMBINATION_SUM_H
#define LC_216_COMBINATION_SUM_H
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
        vector<vector<int>> result;
        void Func(int k, int target, vector<int>& current, int index, vector<int>& candidates)
        {
                if (k == 0 && target > 0 || target == 0 && k > 0)
                {
                        return;
                } else if (k == 0 && target == 0)
                {
                        result.push_back(current);
                        return;
                } else {
                        for (int i = index; i < candidates.size() && candidates[i] <= target; ++i)
                        {
                                current.push_back(candidates[i]);
                                Func(k - 1, target - candidates[i], current, i + 1, candidates);
                                current.pop_back();
                        }
                }
        }
        vector<vector<int>> CombinationSum(int k, int n)
        {
                vector<int> candidates = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
                if (k == 1 && n <= 9)
                {
                        return{ { n } };
                }else if (n == 1 && k != 1)
                {
                        return{};
                } else {
                        vector<int> current;
                        Func(k, n, current, 0, candidates);
                }
                return result;
        }
};

void test216(void)
{
        Solution sol;
        vector<vector<int>> result = sol.CombinationSum(3, 9);
}
#endif