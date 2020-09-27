#ifndef LC_57_INSERT_SUBINTERVAL_H
#define LC_57_INSERT_SUBINTERVAL_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
���������䣬������غϲ��־ͺϲ������䣬�γ��µ����䣬̰���㷨ò��Ҳ����Ҫ������������
���Ҳ��ظ����䣬�������������Ҫ���������end����
*/

class Solution
{
public:
        vector<vector<int>> ans;
        vector<vector<int>> Insert(vector <vector<int>>& intervals, vector<int>& newIntervals)
        {
                bool flag = false;//���ڼ�¼new�����Ƿ��Ѿ�����ans
                sort(intervals.begin(), intervals.end());
                for (int i = 0; i < intervals.size(); ++i)
                {
                        if (newIntervals[0] > intervals[i][1])
                        {
                                ans.emplace_back(intervals[i]);
                                continue;
                        }
                        if (newIntervals[1] < intervals[i][0])
                        {
                                ans.emplace_back(newIntervals);
                                flag = !flag;
                                for (; i < intervals.size(); ++i)
                                {
                                        ans.emplace_back(intervals[i]);
                                }
                                break;
                        }
                        newIntervals[0] = min(newIntervals[0], intervals[i][0]);
                        newIntervals[1] = max(newIntervals[1], intervals[i][1]);
                }
                if (!flag)
                {
                        ans.emplace_back(newIntervals);
                }
                return ans;
        }
};

void test57(void)
{
        //vector<vector<int>> intervals(5, vector<int>(2, 0));
        //for (int i = 0; i < intervals.size(); ++i)
        //{
        //        intervals[i][0] = i;
        //        intervals[i][1] = i + 5;
        //}
        vector<vector<int>> intervals = { { 1, 3 }, { 6, 8 }, { 9, 10 } };
        vector<int> newIntervals = { 2, 7 };
        Solution sol;
        vector<vector<int>> ans = sol.Insert(intervals, newIntervals);
        for (int i = 0; i < ans.size(); ++i)
        {
                printf("%d\t%d\n", ans[i][0], ans[i][1]);
        }
        system("pause");
}

#endif
