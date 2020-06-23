#ifndef LC_105_PREORDER_INORDER_TO_CONSTRUCT_BINARY_TREE_H
#define LC_105_PREORDER_INORDER_TO_CONSTRUCT_BINARY_TREE_H
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>
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

class Solution
{
private:
        unordered_map<int, int> index;
public:
        TreeNode* MyBuildTree(const vector<int>& preorder, const vector<int>& inorder,
                int preLeft, int preRight, int inLeft, int inRight)
        {
                if (preLeft > preRight)
                {
                        return nullptr;
                }
                int preRoot = preLeft;
                int inRoot = index[preorder[preRoot]];
                TreeNode* root = new TreeNode(preorder[preRoot]);
                int sizeLeftSubTree = inRoot - inLeft;
                root->left = MyBuildTree(preorder, inorder, preLeft + 1, preLeft + sizeLeftSubTree, inLeft, inRoot - 1);
                root->right = MyBuildTree(preorder, inorder, preLeft + sizeLeftSubTree + 1, preRight, inRoot + 1, inRight);
                return root;
        }
        TreeNode* BuildTree(vector<int>& preorder, vector<int>& inorder)
        {
                int n = preorder.size();
                for (int i = 0; i < n; ++i)
                {
                        index[inorder[i]] = i;
                }
                return MyBuildTree(preorder, inorder, 0, n - 1, 0, n - 1);
        }
};

#endif
