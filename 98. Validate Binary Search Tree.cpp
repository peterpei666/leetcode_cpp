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
    bool valid(TreeNode* node, long long l, long long r)
    {
        if (node == nullptr)
        {
            return true;
        }
        if (node->val <= l || node->val >= r)
        {
            return false;
        }
        return valid(node->left, l, node->val) && valid(node->right, node->val, r);
    }
    
public:
    bool isValidBST(TreeNode* root)
    {
        return valid(root, LLONG_MIN, LLONG_MAX);
    }
};
