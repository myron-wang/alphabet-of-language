#ifndef LC_95_DIFFERENT_BINARY_SEARCH_TREE_H
#define LC_95_DIFFERENT_BINARY_SEARCH_TREE_H

#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;

/*
自动生成二叉搜索树
*/

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
        vector<TreeNode*> helper(int start, int end)
        {
                vector<TreeNode*> ret;
                if (start > end)
                {
                        ret.push_back(nullptr);
                }
                for (int i = start; i <= end; ++i)
                {
                        vector<TreeNode*> left = helper(start, i - 1);
                        vector<TreeNode*> right = helper(i + 1, end);
                        for (auto l : left)
                        {
                                for (auto r : right)
                                {
                                        TreeNode* root = new TreeNode(i);
                                        root->left = l;
                                        root->right = r;
                                        ret.push_back(root);
                                }
                        }
                }
                return ret;
        }
        vector<TreeNode*> GenerateTrees(int n)
        {
                vector<TreeNode*> ret;
                if (n == 0)
                {
                        return ret;
                }
                ret = helper(1, n);
                return ret;
        }
};

class BinaryTree
{
public:
        vector<int> PreorderTraversal(TreeNode* root)
        {
                stack<TreeNode*> s;
                vector<int> v;
                TreeNode* rt = root;
                while (rt || s.size())
                {
                        while (rt)
                        {
                                s.push(rt->right);
                                v.push_back(rt->val);
                                rt = rt->left;
                        }
                        rt = s.top();
                        s.pop();
                }
                return v;
        }
        vector<int> PosorderTraversal(TreeNode* root)
        {
                stack<TreeNode*> s;
                vector<int> v;
                TreeNode* rt = root;
                while (rt || s.size())
                {
                        while (rt)
                        {
                                s.push(rt->left);
                                v.push_back(rt->val);
                                rt = rt->right;
                        }
                        rt = s.top();
                        s.pop();
                }
                reverse(v.begin(), v.end());
                return v;
        }
        vector<int> InorderTraversal(TreeNode* root)
        {
                stack<TreeNode*> s;
                vector<int> v;
                TreeNode* rt = root;
                while (rt || s.size())
                {
                        while (rt)
                        {
                                s.push(rt);
                                rt = rt->left;
                        }
                        rt = s.top();
                        s.pop();
                        v.push_back(rt->val);
                        rt = rt->right;
                }
                return v;
        }
};

void test95(void)
{
        Solution sol;
        vector<TreeNode*> result = sol.GenerateTrees(3);

}
#endif