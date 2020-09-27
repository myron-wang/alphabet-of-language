#ifndef LC_207_SCHRDULE_CARD_H
#define LC_207_SCHRDULE_CARD_H

#include <algorithm>
#include <queue>
#include <string>
#include <vector>
using namespace std;
/*
���������ж����޻�����ϸ��
*/
class Solution
{
public:
        bool CanFinish(int numCourse, vector<vector<int>>& prerequisites)
        {
                vector<int> v;
                vector<int> indegree(numCourse, 0);
                vector<vector<int>> graph(numCourse, v);
                for (int i = 0; i < prerequisites.size(); ++i)
                {
                        indegree[prerequisites[i][0]]++;
                        graph[prerequisites[i][1]].push_back(prerequisites[i][0]); // ��ĳ���
                }
                // �����Ϊ��ĵĶ������
                queue<int> myqueue;
                for (int i = 0; i < numCourse; ++i)
                {
                        if (indegree[i] == 0)
                        {
                                myqueue.push(i);
                        }
                }
                int cnt = 0;
                while (!myqueue.empty())
                {
                        int tmp = myqueue.front();
                        myqueue.pop();
                        cnt++;
                        for (int i = 0; i < graph[tmp].size(); ++i)
                        {
                                indegree[graph[tmp][i]]--;
                                if (indegree[graph[tmp][i]] == 0)
                                {
                                        myqueue.push(graph[tmp][i]);
                                }
                        }
                }
                return cnt == numCourse;
        }
};
#endif