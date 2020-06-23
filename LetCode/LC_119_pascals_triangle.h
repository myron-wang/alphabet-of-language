#ifndef LC_119_PASCALS_TRIANGLE_H
#define LC_119_PASCALS_TRIANGLE_H

#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
        vector<int> GetRow(int rowIndex)
        {
                vector<int> res(rowIndex + 1);
                res[0] = 1;
                for (int i = 1; i <= rowIndex; ++i)
                {
                        for (int j = i; j >= 1; --j)
                        {
                                res[j] += res[j - 1];
                        }
                }
                return res;
        }
};

void test119(void)
{
        Solution sol;
        vector<int> res = sol.GetRow(4);
        for (int i = 0; i < res.size(); ++i)
        {
                printf("%d\t", res[i]);
        }
        printf("\n");
}

#endif