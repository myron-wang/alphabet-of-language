#ifndef LC_29_DIVIDE_TWO_NUMBERS_H
#define LC_29_DIVIDE_TWO_NUMBERS_H
#include <algorithm>
#include <vector>
using namespace std;

/*
只用加减做除法
*/
class Solution
{
public:
        int Divide(int divide, int divisor)
        {
                if (divide == 0)
                {
                        return 0;
                }
                if (divisor == 1)
                {
                        return divide;
                }
                if (divisor == -1)
                {
                        if (divide > INT_MIN)
                        {
                                return -divide;
                        }
                        return INT_MAX;
                }
                long a = divide;
                long b = divisor;
                int sign = 1;
                if (a > 0 && b < 0 || a < 0 && b > 0)
                {
                        sign = -1;
                }
                a = a > 0 ? a : -a;
                b = b > 0 ? b : -b;
                long res = div(a, b);
                if (sign > 0)
                {
                        return res > INT_MAX ? INT_MAX : res;
                }
                return -res;
        }
        int div(long a, long b)
        {
                if (a < b)
                {
                        return 0;
                }
                long count = 1;
                long tb = b;
                while ((tb+tb) <= a)
                {
                        count = count + count;
                        tb = tb + tb;
                }
                return count + div(a - tb, b);
        }
};

void test29(void)
{
        Solution sol;
        int result = sol.Divide(10, 3);
        printf("%d\n", result);
}
#endif