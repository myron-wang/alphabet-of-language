#ifndef LC_28_STRSTR_H
#define LC_28_STRSTR_H
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
KMPÆ¥Åä×Ö·û´®
*/
class Solution
{
public:
        int Strstr(string haystack, string needle)
        {
                if (!needle.size())
                {
                        return 0;
                }
                if (!haystack.size())
                {
                        return -1;
                }
                int j = -1;
                int i = 0;
                vector<int> b(needle.size() + 1);
                b[i] = j;
                while (i < needle.size())
                {
                        while (j >= 0 && needle[i] != needle[j])
                        {
                                j = b[j];
                        }
                        i++;
                        j++;
                        b[i] = j;
                }

                j = 0;
                i = 0;
                while (j < haystack.size())
                {
                        while (i >=0 && needle[i] != haystack[j])
                        {
                                i = b[i];
                        }
                        i++;
                        j++;
                        if (i == needle.size())
                        {
                                return j - needle.size();
                        }
                }
                return -1;
        }
};

void test28(void)
{
        string haystack = "hello";
        string needle = "ll";
        Solution sol;
        int result = sol.Strstr(haystack, needle);
        printf("%d\n", result);
}
#endif