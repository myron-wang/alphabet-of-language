#ifndef LENGTH_OF_LONGEST_SUB_STRING_H
#define LENGTH_OF_LONGEST_SUB_STRING_H
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
using namespace std;

/*
获取字符串不重复字符的最长子串的长度
*/

class LongestSubStr
{
public:
        int MaxLength(int num_a, int num_b)
        {
                return num_a > num_b ? num_a : num_b;
        }
        int GetLengthOfLongestSubString(string str)
        {
                unordered_set<char> unord_set;
                int idx_right = -1;
                int max_len_sub_str = 0;
                int len_str = str.size();
                for (int i = 0; i < len_str; ++i)
                {
                        if (i != 0)
                        {
                                unord_set.erase(str[i - 1]);
                        }
                        while (idx_right + 1 < len_str && !unord_set.count(str[idx_right + 1]))
                        {
                                unord_set.insert(str[idx_right + 1]);
                                ++idx_right;
                        }
                        max_len_sub_str = MaxLength(max_len_sub_str, idx_right - i + 1);
                }
                return max_len_sub_str;
        }
        int GetLengthOfLongestSubString2(string str)
        {//abcdbcf
                unordered_map<char, int> windows;
                int left = 0;
                int right = 0;
                int res = 0;
                while (right < str.size())
                {
                        char c = str[right];
                        right++;
                        windows[c]++;
                        while (windows[c] > 1)
                        {
                                char d = str[left];
                                left++;
                                windows[d]--;
                        }
                        res = max(res, right - left);
                }
                return res;
        }
};

void test1(void);

#endif