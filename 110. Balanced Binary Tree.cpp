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
    int depth(TreeNode* node, int cur)
    {
        if (node == nullptr)
        {
            return cur;
        }
        return max(depth(node->left, cur + 1), depth(node->right, cur + 1));
    }
    
public:
    bool isBalanced(TreeNode* root)
    {
        if (!root)
        {
            return true;
        }
        return abs(depth(root->left, 0) - depth(root->right, 0)) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }
};
