#ifndef LC_129_SUM_OF_ROOT_TO_LEAF_H
#define LC_129_SUM_OF_ROOT_TO_LEAF_H
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

/*
计算所有从根节点到叶节点所有路径组成的数字之和
*/

class Solution
{
public:
        int ClaculateSumPath(vector<int>& numBuf, int iLevel)
        {
                int iSum = 0;
                for (int i = 0; i <= iLevel; ++i)
                {
                        iSum = iSum * 10;
                        iSum += numBuf[i];
                }
                return iSum;
        }

        void Backtrack(TreeNode* root, vector<int>& numBuf, int iLevel, int* iRet)
        {
                if (root == NULL)
                {
                        return;
                }
                numBuf[iLevel] = root->val;
                if (root->left == NULL && root->right == NULL)
                {
                        *iRet += ClaculateSumPath(numBuf, iLevel);
                        return;
                }
                if (root->left)
                {
                        Backtrack(root->left, numBuf, iLevel + 1, iRet);
                }
                if (root->right) {
                        Backtrack(root->right, numBuf, iLevel + 1, iRet);
                }
                return;
        }

        int SumOfRootToLeaf(TreeNode* root)
        {
                int iRet = 0;
                if (root == NULL)
                {
                        return iRet;
                }
                vector<int> numBuf;
                Backtrack(root, numBuf, 0, &iRet);
                return iRet;
        }
};

#endif
