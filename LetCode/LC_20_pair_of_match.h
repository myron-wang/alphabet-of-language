#ifndef LC_20_PAIR_OF_MATCH_H
#define LC_20_PAIR_OF_MATCH_H

#include <stack>
#include <stdlib.h>
#include <stdio.h>
#include <string>
using namespace std;

class Solution
{
public:
        bool IsMatchingBrackets(char a, char b)
        {
                if (a == '(' && b == ')' || a == '[' && b == ']' || a == '{' && b == '}')
                {
                        return true;
                }
                return false;
        }
        bool IsValidString(string str)
        {
                if (str.size() == 0)
                {
                        return true;
                }
                stack<char> myStack;
                int i = 1;
                myStack.push(str.at(0));
                while (i < str.size())
                {
                        if (myStack.empty())
                        {
                                myStack.push(str.at(i));
                                if (++i >= str.size())
                                {
                                        return false;
                                }
                        }
                        IsMatchingBrackets(myStack.top(), str.at(i)) ? myStack.pop() : myStack.push(str.at(i));
                        i++;
                }
                return myStack.empty() ? true : false;
        }
};

void test20(void)
{
        string str = "{}{}[()]";
        Solution isMatch;
        bool isTrue = isMatch.IsValidString(str);
        printf("打印是否正确:%d\n", isTrue);
        system("pause");
}
#endif