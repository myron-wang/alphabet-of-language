#ifndef LC_93_RECOVERY_IP_ADDRESS_H
#define LC_93_RECOVERY_IP_ADDRESS_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
转换数字字符串为IP地址，回溯法
*/
class Solution
{
public:
        bool IsValid(string str)
        {
                int val = stoi(str);
                if (val > 255)
                {
                        return false;
                }
                if (str.size() >= 2 && str[0] == '0')
                {
                        return false;
                }
                return true;
        }
        void DFS(vector<string> &res, vector<string> &path, string str, int pos)
        {
                int maxLen = (4 - path.size()) * 3;
                if (str.size() - pos > maxLen)
                {
                        return;
                }
                if (path.size() == 4 && pos == str.size())
                {
                        string temp = "";
                        for (int i = 0; i < 4; ++i)
                        {
                                temp += path[i];
                                if (i != 3)
                                {
                                        temp += '.';
                                }
                        }
                        res.emplace_back(temp);
                }
                for (int j = pos; j < str.size() && j <= pos + 2; ++j)
                {
                        string ip = str.substr(pos, j - pos + 1);
                        if (!IsValid(ip))
                        {
                                continue;
                        }
                        path.emplace_back(ip);
                        DFS(res, path, str, j + 1);
                        path.pop_back();
                }
        }

        vector<string> RestoreIPAddress(string str)
        {//应该检查str是否是NULL和str中含有非数字的字符
                vector<string> res;
                vector<string> path;
                if (str.size() < 4)
                {
                        return res;
                }
                DFS(res, path, str, 0);
                return res;
        }
};

void test93(void)
{
        string str = "234562314";
        Solution sol;
        vector<string> result = sol.RestoreIPAddress(str);
        for (int i = 0; i < result.size(); ++i)
        {
                printf("%s\n", result[i].c_str());
        }
}

#endif
