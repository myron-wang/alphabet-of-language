#ifndef LC_218_SKYLINE_H
#define LC_218_SKYLINE_H
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
        vector<vector<int>> GetSkyLine(vector<vector<int>>& buildings)
        {
                //multiset 具有自动排序的功能，小的在前面，先比较first，如果first相同再比较second
                multiset<pair<int, int>> all;
                vector<vector<int>> res;
                for (auto& e : buildings)
                {
                        all.insert(make_pair(e[0], -e[2]));
                        all.insert(make_pair(e[1], e[2]));
                }
                multiset<int> heights({ 0 });
                vector<int> last = { 0, 0 };
                for (auto& p : all)
                {
                        if (p.second < 0)
                        {
                                heights.insert(-p.second);
                        } else {
                                heights.erase(heights.find(p.second));
                        }
                        auto maxHeight = *heights.rbegin();
                        if (last[1] != maxHeight)
                        {
                                last[0] = p.first;
                                last[1] = p.second;
                                res.push_back(last);
                        }
                }
                return res;
        }
};
#endif