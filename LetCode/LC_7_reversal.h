#ifndef LC_7_REVERSAL_H
#define LC_7_REVERSAL_H
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
        int reverse(int x)
        {
                int flag = 1;
                if (x == INT_MAX || x == INT_MIN)
                {
                        return 0;
                }
                if (x < 0)
                {
                        x = -x;
                        flag = -1;
                }
                while (x % 10 == 0 && x > 0)
                {
                        x = x / 10;
                }
                long long num = 0;
                while (x > 0)
                {
                        num = num * 10 + x % 10;
                        x = x / 10;
                }
                num = num * flag;
                if (num > INT_MAX || num < INT_MIN)
                {
                        return 0;
                }
                return num;
        }
};

void test7(void)
{
        int num = 123;
        Solution sol;
        int result = sol.reverse(num);
        printf("%d\n", result);
}
#endif