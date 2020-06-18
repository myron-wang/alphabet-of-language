#ifndef LONGEST_PALINDROME_SUBSTRING_H
#define LONGEST_PALINDROME_SUBSTRING_H

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

/*
最长回文子串问题
*/

class Palindrome
{
public:
        pair<int, int> ExpandAroundCenter(const string& str, int left, int right)
        {
                while (left >= 0 && right < str.size() && str[left] == str[right])
                {
                        --left;
                        ++right;
                }
                return { left + 1, right - 1 };
        }
        string LongestPalindromeSubString(string str)
        {
                int start = 0, end = 0;
                pair<int, int> ret_a, ret_b;
                for (int i = 0; i < str.size(); ++i)
                {
                        ret_a = ExpandAroundCenter(str, i, i);
                        ret_b = ExpandAroundCenter(str, i, i + 1);
                        if (ret_a.second - ret_a.first > end - start)
                        {
                                start = ret_a.first;
                                end = ret_a.second;
                        }
                        if (ret_b.second - ret_b.first > end - start)
                        {
                                start = ret_b.first;
                                end = ret_b.second;
                        }
                }
                return str.substr(start, end - start + 1);
        }
};

void test3(void)
{
        string str = "abcdcbafgt";
        Palindrome test_a;
        string substr00 = test_a.LongestPalindromeSubString(str);
        printf("最长子串是%s\n", substr00.c_str());
}


#endif