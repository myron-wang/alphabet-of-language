#ifndef LC_107_LAYER_TRAVERSAL_OF_BINARY_TREE_H
#define LC_107_LAYER_TRAVERSAL_OF_BINARY_TREE_H

#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode
{
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(NULL), right(NULL)
        {
        }
};

/*
µ¹Ðð²ã¼¶±éÀú¶þ²æÊ÷
*/

class Solution
{
public:
        /* plan A */
        int GetDepth(TreeNode* root)
        {
                if (root == NULL)
                {
                        return 0;
                }
                return max(GetDepth(root->left), GetDepth(root->right)) + 1;
        }
        void dfs(TreeNode* root, int depth, vector <vector<int>>& ans, int n)
        {
                if (root == NULL)
                {
                        return;
                }
                ans[n - depth].push_back(root->val);
                dfs(root->left, depth + 1, ans, n);
                dfs(root->right, depth + 1, ans, n);
        }
        vector<vector<int>> LevelOrderBottom(TreeNode* root)
        {
                int n = GetDepth(root);
                vector<vector<int>> ans(n, vector<int>());
                dfs(root, 0, ans, n - 1);
                return ans;
        }

        /* plan B */
        vector<vector<int>> levelOrderBottom(TreeNode* root)
        {
                vector<vector<int>> ans;
                if (root == NULL)
                {
                        return;
                }
                queue<TreeNode*> q;
                q.push(root);
                while (!q.size())
                {
                        vector<int> temp;
                        int len = q.size();
                        for (int i = 0; i < len; ++i)
                        {
                                TreeNode* node = q.front();
                                q.pop();
                                temp.push_back(node->val);
                                if (node->left != NULL)
                                {
                                        q.push(node->left);
                                }
                                if (node->right != NULL)
                                {
                                        q.push(node->right);
                                }
                        }
                        ans.insert(ans.begin(), temp);
                }
                return ans;
        }
};

#endif