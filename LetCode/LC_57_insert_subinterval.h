#ifndef LC_57_INSERT_SUBINTERVAL_H
#define LC_57_INSERT_SUBINTERVAL_H

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
插入子区间，如果有重合部分就合并子区间，形成新的区间，贪心算法貌似也是主要讲得区间问题
查找不重复区间，插气球问题等需要按照区间的end排序
*/

class Solution
{
public:
        vector<vector<int>> ans;
        vector<vector<int>> Insert(vector <vector<int>>& intervals, vector<int>& newIntervals)
        {
                bool flag = false;//用于记录new区间是否已经加入ans
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
