#ifndef LC_108_ARRAY_TO_BINARY_SEARCH_TREE_H
#define LC_108_ARRAY_TO_BINARY_SEARCH_TREE_H

#include <vector>
#include <string>
#include <algorithm>

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
public:
        TreeNode* bst(vector<int> nums, int left, int right)
        {
                if (left > right)
                {
                        return NULL;
                }
                int mid = left + (right - left) / 2;
                TreeNode* root = new TreeNode(nums[mid]);
                root->left = bst(nums, left, mid - 1);
                root->right = bst(nums, mid + 1, right);
                return root;
        }
        TreeNode* SortedArrayToBST(vector<int>& nums)
        {
                return bst(nums, 0, nums.size() - 1);
        }
};

#endif
