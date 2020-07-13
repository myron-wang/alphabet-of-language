#ifndef LC_165_COMPARE_VERSIOON_H
#define LC_165_COMPARE_VERSIOON_H
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
        int CompareVersion(string v1, string v2)
        {
                int i = 0, j = 0;
                while (i < v1.size() || j < v2.size())
                {
                        int x = i, y = j;
                        while (x < v1.size() && v1[x] != '.')
                        {
                                x++;
                        }
                        while (y < v2.size() && v2[y] != '.')
                        {
                                y++;
                        }
                        
                        int a = (i == x) ? 0 : atoi(v1.substr(i, x - i).c_str());
                        int b = (j == y) ? 0 : atoi(v2.substr(j, y - j).c_str());
                        if (a > b)
                        {
                                return 1;
                        }else if (a < b)
                        {
                                return -1;
                        }
                        i = x + 1;
                        j = y + 1;
                }
                return 0;
        }
};

void test165(void)
{
        string v1 = "1.3.005.01";
        string v2 = "1.3.05.1";
        Solution sol;
        int result = sol.CompareVersion(v1, v2);
        printf("%d\n", result);
}
#endif