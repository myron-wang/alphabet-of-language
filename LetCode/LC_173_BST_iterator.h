#ifndef LC_173_BSTITERATOR_H
#define LC_173_BSTITERATOR_H
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
using namespace std;
/* 构造二叉搜索树迭代器 */
struct TreeNode
{
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(NULL), right(NULL)
        {
        }

};
class BSTIterator
{
public:
        BSTIterator(TreeNode* root)
        {
                while (root)
                {
                        st.push(root);
                        root = root->left;
                }
        }
        int Next()
        {
                TreeNode* curNode = st.top();
                st.pop();
                int ret = curNode->val;
                curNode = curNode->right;
                while (curNode)
                {
                        st.push(curNode);
                        curNode = curNode->left;
                }
                return ret;
        }
        bool HasNext()
        {
                return !st.empty();
        }
private:
        stack<TreeNode*> st;
};
#endif