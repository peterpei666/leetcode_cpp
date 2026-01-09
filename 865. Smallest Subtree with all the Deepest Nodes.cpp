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
    int depth(int current,TreeNode* node)
    {
        if (node == nullptr)
        {
            return current;
        }
        else
        {
            int a = depth(current + 1, node->left);
            int b = depth(current + 1, node->right);
            return max(a, b);
        }
    }

public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root)
    {
        int l = depth(0, root->left);
        int r = depth(0, root->right);
        if (l > r)
        {
            return subtreeWithAllDeepest(root->left);
        }
        else if (l < r)
        {
            return subtreeWithAllDeepest(root->right);
        }
        else
        {
            return root;
        }
    }
};
