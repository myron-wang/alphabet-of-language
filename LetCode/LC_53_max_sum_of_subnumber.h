#ifndef LC_53_MAX_SUM_OF_SUBNUMBER_H
#define LC_53_MAX_SUM_OF_SUBNUMBER_H

#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

class BinaryTreeNode
{
public:
        int value;
        BinaryTreeNode* left;
        BinaryTreeNode* right;
};

class Solution
{
public:
        /*
        求取子数字串的最大和
        */
        int MaxSumOfSubNumber(vector<int>& nums)
        {
                int pre = 0, maxSum = 0;
                for (auto x : nums)
                {
                        pre = max(pre + x, x);
                        maxSum = max(pre, maxSum);
                }
                return maxSum;
        }
        
        /*
        从上到下依次顺序横向打印二叉树的值
        */
        void PrintFromTopToEnd(BinaryTreeNode* pTreeRoot)
        {
                if (!pTreeRoot)
                {
                        return;
                }
                deque<BinaryTreeNode*> nodeDeque;
                nodeDeque.push_back(pTreeRoot);
                while (nodeDeque.size() > 0)
                {
                        BinaryTreeNode* node = nodeDeque.front();
                        printf("%d\t", node->value);
                        nodeDeque.pop_front();
                        if (node->left)
                        {
                                nodeDeque.push_back(node->left);
                        }
                        if (node->right)
                        {
                                nodeDeque.push_back(node->right);
                        }
                }
        }
};


void test53(void)
{
        Solution sol;
        vector<int> nums = { 2, -5, 4, 6, -9, 8, -5, 6, 9 };
        int maxSum = sol.MaxSumOfSubNumber(nums);
        printf("max sum of subnumber is: %d\n", maxSum);
}

#endif