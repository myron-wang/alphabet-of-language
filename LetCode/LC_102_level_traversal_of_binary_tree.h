#ifndef LC_102_LEVEL_TRAVERSAL_OFBINARY_TREE_H
#define LC_102_LEVEL_TRAVERSAL_OFBINARY_TREE_H

#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

class TreeNode
{
public:
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(NULL), right(NULL)
        {
        }
};

class Solution
{
public:
        /* BFS */
        vector<vector<int>> LevelOrederOfBFS(TreeNode* root)
        {
                queue<TreeNode*> treeQue;
                treeQue.push(root);
                vector<vector<int>> res;
                while (treeQue.size() != 0)
                {
                        int size = treeQue.size();
                        vector<int> level;
                        while (size--)
                        {
                                TreeNode* cur = treeQue.front();
                                treeQue.pop();
                                if (!cur)
                                {
                                        continue;
                                }
                                level.push_back(cur->val);
                                treeQue.push(cur->left);
                                treeQue.push(cur->right);
                        }
                        if (level.size() != 0)
                        {
                                res.push_back(level);
                        }
                }
                return res;
        }
        /* DFS */
        void DFS(vector<vector<int>> &res, TreeNode* root, int level)
        {
                if (!root)
                {
                        return;
                }
                if (level >= res.size())
                {
                        res.push_back(vector<int>());
                }
                res[level].push_back(root->val);
                DFS(res, root->left, level + 1);
                DFS(res, root->right, level + 1);
        }
        vector<vector<int>> LevelOrderOfDFS(TreeNode* root)
        {
                vector<vector<int>> res;
                if (!root)
                {
                        return res;
                }
                DFS(res, root, 0);
                return res;
        }
};

#endif
