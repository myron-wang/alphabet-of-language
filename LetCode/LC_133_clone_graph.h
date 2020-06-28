#ifndef LC_133_CLONE_GRAPG_H
#define LC_133_CLONE_GRAPG_H

#include <algorithm>
#include <string>
#include <vector>
#include <list>
using namespace std;

class Node
{
public:
        int val;
        vector<Node> neighbors;
        Node(int x) : val(x), neighbors(NULL)
        {
        }
};

class Solution
{
public:
        Node* used[101];
        Node* CloneGraph(Node* node)
        {
                if (node == NULL)
                {
                        return node;
                }
                if (used[node->val])
                {
                        return used[node->val];
                }
                Node* p = new Node(node->val);
                used[node->val] = p;
                vector<Node*> tp(node->neighbors);
                for (int i = 0; i < tp.size(); i++)
                {
                        p->neighbors.push_back(CloneGraph(tp[i]));
                }
                return p;
        }
        
};

#endif