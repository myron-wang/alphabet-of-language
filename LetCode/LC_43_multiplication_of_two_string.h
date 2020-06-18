#ifndef LC_43_MULTIPLICATION_OF_TWO_STRING
#define LC_43_MULTIPLICATION_OF_TWO_STRING

#include <vector>
#include <string>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

/*
两个字符串数字求积
*/

class Solution
{
public:
        string MultiplyOfTwoString(string strA, string strB)
        {
                if (strA == "0" || strB == "0")
                {
                        return "0";
                }
                vector<int> result(strA.size() + strB.size() + 1, 0);
                for (int i = 0; i < strA.size(); ++i)
                {
                        for (int j = 0; j < strB.size(); ++j)
                        {
                                result[i + j + 1] += (strA.at(i) - '0') * (strB.at(j) - '0');

                        }
                }
                for (int k = result.size() - 1; k > 0; --k)
                {
                        if (result[k] < 10)
                        {
                                continue;
                        }
                        result[k - 1] += result[k] / 10;
                        result[k] = result[k] % 10;
                }
                string str = "";
                bool isZero = true;
                for (int l = 0; l < result.size() - 1; ++l)
                {
                        if (isZero && result[l] == 0)
                        {
                                continue;
                        }
                        isZero = false;
                        str.push_back(result[l] + '0');
                }
                return str;
        }
};

void test43(void)
{
        Solution sol;
        string strA = "999";
        string strB = "999";
        string str = sol.MultiplyOfTwoString(strA, strB);
        printf("multiply of two string is: %s\n", str.c_str());
        system("pause");
}

#endif