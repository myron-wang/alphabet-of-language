#ifndef LC_89_GRAYCODE_H
#define LC_89_GRAYCODE_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
格雷码编码，找规律计算而得
*/

class Solution
{
public:
        vector<int> GrayCode(int n)
        {
                int shift = 1;
                vector<int> res;
                while (n >= 0)
                {
                        if (res.size() == 0)
                        {
                                res.push_back(0);
                        } else {
                                for (int i = shift - 1; i >= 0; --i) {
                                        res.push_back(res[i] + shift);
                                }
                                shift *= 2;
                        }
                        --n;
                }
                return res;
        }
};

void test89(void)
{
        Solution sol;
        vector<int> result = sol.GrayCode(0);
        for (int i = 0; i < result.size(); ++i)
        {
                printf("%d\t", result[i]);
        }
        printf("\n");
}


#endif