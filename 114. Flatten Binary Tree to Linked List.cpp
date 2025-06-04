#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    TreeNode* tail;
    
    void construct(TreeNode* node)
    {
        tail->left=nullptr;
        tail->right=node;
        tail=node;
        TreeNode* l=node->left;
        TreeNode* r=node->right;
        if(l)
        {
            construct(l);
        }
        if(r)
        {
            construct(r);
        }
    }
    
    void flatten(TreeNode* root)
    {
        if(root==nullptr)
        {
            return;
        }
        TreeNode dummy;
        tail=&dummy;
        construct(root);
    }
};
