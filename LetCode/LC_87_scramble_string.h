#ifndef LC_87_SCRAMBLE_STRING_H
#define LC_87_SCRAMBLE_STRING_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
ÅÐ¶ÏÁ½¸ö×Ö·û´®ÊÇ·ñÊÇÈÅÂÒ×Ö·û´®
*/

class Solution
{
public:
        bool Recursion(string s1, string s2)
        {
                if (s1 == s2)
                {
                        return true;
                }
                string t1 = s1, t2 = s2;
                sort(t1.begin(), t1.end());
                sort(t2.begin(), t2.end());
                if (t1 != t2)
                {
                        return false;
                }
                for (int i = 1; i < s1.size(); ++i)
                {
                        bool flag1 = Recursion(s1.substr(0, i), s2.substr(0, i)) && Recursion(s1.substr(i, s1.size() - i), s2.substr(i, s2.size() - i));
                        bool flag2 = Recursion(s1.substr(0, i), s2.substr(s2.size() - i, i)) && Recursion(s1.substr(i, s1.size() - i),
                                s2.substr(0, s2.size() - i));
                        if (flag1 || flag2)
                        {
                                return true;
                        }
                }
                return false;
        }
};

void test87(void)
{
        string s1 = "great";
        string s2 = "rgeat";
        Solution sol;
        bool is_true = sol.Recursion(s1, s2);
        printf("ÊÇ·ñÊÇÈÅÂÒ×Ö·û´®£º%d\n", is_true);
}

#endif