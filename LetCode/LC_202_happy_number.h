#ifndef LC_202_HAPPY_NUMBER_H
#define LC_202_HAPPY_NUMBER_H
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class Solution
{
public:
        static int GetNext(int n)
        {
                int totalSum = 0;
                while (n > 0)
                {
                        int d = n % 10;
                        n = n / 10;
                        totalSum += d * d;
                }
                return totalSum;
        }
        bool IsHappy(int n)
        {
                int slowRunner = n;
                int fastRunner = GetNext(n);
                while (fastRunner != 1 && slowRunner != fastRunner)
                {
                        slowRunner = GetNext(slowRunner);
                        fastRunner = GetNext(GetNext(fastRunner));
                }
                return fastRunner == 1;
        }
};
void test202(void)
{
        Solution sol;
        bool result = sol.IsHappy(4);
        printf("%d\n", result);
}
#endif