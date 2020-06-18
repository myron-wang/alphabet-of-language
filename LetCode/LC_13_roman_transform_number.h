#ifndef LC_13_ROMAN_TRANSFORM_NUMBER_H
#define LC_13_ROMAN_TRANSFORM_NUMBER_H

#include <string>
#include <stdlib.h>
#include <stdio.h>
#include <unordered_map>

using namespace std;

/*
罗马数字转数字问题
*/

int RomanTansformNumber(string str)
{
        unordered_map<char, int> num_map = { { 'I', 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50 }, { 'C', 100 }, { 'D', 500 }, { 'M', 1000 } };
        int str_len = str.size();
        int sum = 0, neg = 0;
        for (int i = 0; i < str_len - 1; ++i)
        {
                if (num_map[str[i]] < num_map[str[i + 1]])
                {
                        neg -= num_map[str[i]];
                }
                else {
                        sum += num_map[str[i]];
                }
        }
        sum += num_map[str.back()];
        return sum + neg;
}

void test13(void)
{
        string str = "MCMLXIX";
        int digits = RomanTansformNumber(str);
        printf("%s：%d\n", str.c_str(), digits);
}

#endif