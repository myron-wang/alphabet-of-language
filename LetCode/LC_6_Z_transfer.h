#ifndef LC_6_Z_TRANSFER_H
#define LC_6_Z_TRANSFER_H
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
        string Convert(string s, int numRows)
        {
                if (numRows == 1)
                {
                        return s;
                }
                vector<string> rows(min(numRows, int(s.size())));
                int curRow = 0;
                bool goingDown = false;
                for (char c : s)
                {
                        rows[curRow] += c;
                        if (curRow == 0 || curRow == numRows - 1)
                        {
                                goingDown = !goingDown ? true : false;
                        }
                        curRow += goingDown ? 1 : -1;
                }
                string ret;
                for (string row : rows)
                {
                        ret += row;
                }
                return ret;
        }

};

void test6(void)
{
        Solution sol;
        string str = "abcdefgh";
        string result = sol.Convert(str, 3);
        cout << result << endl;
}
#endif