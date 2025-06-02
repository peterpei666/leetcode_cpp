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
    int i,ans;
    
    void inorder(TreeNode* node,int k)
    {
        if(i>=k)
        {
            return;
        }
        if(node->left)
        {
            inorder(node->left,k);
        }
        if(i>k)
        {
            return;
        }
        i++;
        if(i==k)
        {
            ans=node->val;
        }
        if(node->right)
        {
            inorder(node->right,k);
        }
    }
    
    int kthSmallest(TreeNode* root, int k)
    {
        ans=0;
        i=0;
        inorder(root,k);
        return ans;
    }
};
