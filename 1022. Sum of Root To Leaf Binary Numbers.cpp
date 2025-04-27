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
    int sumRootToLeaf(TreeNode* root)
    {
        return sum(root,0);
    }
    
    int sum(TreeNode* node,int cur)
    {
        cur<<=1;
        cur+=node->val;
        if(node->left==nullptr&&node->right==nullptr)
        {
            return cur;
        }
        int l=0,r=0;
        if(node->left)
        {
            l=sum(node->left,cur);
        }
        if(node->right)
        {
            r=sum(node->right,cur);
        }
        return l+r;
    }
};
