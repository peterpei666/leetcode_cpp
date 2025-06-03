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
    void construct(TreeNode* node,int val)
    {
        if(val<node->val)
        {
            if(node->left)
            {
                construct(node->left,val);
                return;
            }
            else
            {
                node->left=new TreeNode(val);
                return;
            }
        }
        else
        {
            if(node->right)
            {
                construct(node->right,val);
                return;
            }
            else
            {
                node->right=new TreeNode(val);
                return;
            }
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder)
    {
        TreeNode* root=new TreeNode(preorder[0]);
        for(int i=1;i<preorder.size();i++)
        {
            construct(root,preorder[i]);
        }
        return root;
    }
};
