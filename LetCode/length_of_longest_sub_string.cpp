#include "length_of_longest_sub_string.h"

void test1(void)
{
        LongestSubStr str;
        string long_str = "abcdbcfda";
        int length_substr = str.GetLengthOfLongestSubString2(long_str);
        printf("������г��ȣ�%d\n", length_substr);
        system("pause");
}