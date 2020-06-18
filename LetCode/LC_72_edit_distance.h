#ifndef LC_72_EDIT_DISTANCE_H
#define LC_72_EDIT_DISTANCE_H

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

/*
求两个单词的编辑距离问题
*/

class Solution
{
public:
        int MinEditDistance(string wordA, string wordB)
        {
                int numA = wordA.size();
                int numB = wordB.size();
                if (numA * numB  == 0)
                {
                        return numA + numB;
                }
                //int dp[numA + 1][numB + 1];
                vector<vector<int>> dp(numA + 1, vector<int>(numB + 1, 0));
                for (int i = 0; i <= numA; ++i)
                {
                        dp[i][0] = i;
                }
                for (int j = 0; j <= numB; ++j)
                {
                        dp[0][j] = j;
                }
                for (int i = 1; i < numA + 1; ++i)
                {
                        for (int j = 1; j < numB + 1; ++j)
                        {
                                int left = dp[i - 1][j] + 1;
                                int down = dp[i][j - 1] + 1;
                                int left_down = dp[i - 1][j - 1];
                                if (wordA.at(i - 1) != wordB.at(j - 1))
                                {
                                        left_down += 1;
                                }
                                dp[i][j] = min(min(left, down), left_down);
                        }
                }
                return dp[numA][numB];
        }
};

void test72(void)
{
        string wordA = "abcde";
        string wordB = "cdea";
        Solution sol;
        int result = sol.MinEditDistance(wordA, wordB);
        cout << "编辑距离为：" << result << endl;
}


#endif