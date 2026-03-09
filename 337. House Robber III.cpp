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
    pair<int, int> dfs(TreeNode* node)
    {
        if (node == nullptr)
        {
            return make_pair(0, 0);
        }
        pair<int, int> left = dfs(node->left);
        pair<int, int> right = dfs(node->right);
        int t1 = max(left.first, left.second) + max(right.first, right.second);
        int t2 = node->val + left.first + right.first;
        return make_pair(t1, t2);
    }
    
public:
    int rob(TreeNode* root)
    {
        pair<int, int> ans = dfs(root);
        return max(ans.first, ans.second);
    }
};
