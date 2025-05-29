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
private:
    void reverse(TreeNode* l,TreeNode* r,bool odd)
    {
        if(l==nullptr||r==nullptr)
        {
            return;
        }
        if(odd)
        {
            swap(l->val,r->val);
        }
        reverse(l->left,r->right,!odd);
        reverse(l->right,r->left,!odd);
    }
    
public:
    TreeNode* reverseOddLevels(TreeNode* root)
    {
        if(root==nullptr)
        {
            return nullptr;
        }
        reverse(root->left,root->right,true);
        return root;
    }
};
