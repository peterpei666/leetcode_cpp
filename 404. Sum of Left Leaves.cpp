#include <iostream>
#include <algorithm>
#include <unordered_map>
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
    int ans;
    
    void dfs(TreeNode* node, bool isLeft)
    {
        if (node == nullptr)
        {
            return;
        }
        if (node->left == nullptr && node->right == nullptr)
        {
            if (isLeft)
            {
                ans += node->val;
            }
            return;
        }
        dfs(node->left, true);
        dfs(node->right, false);
    }
    
public:
    int sumOfLeftLeaves(TreeNode* root)
    {
        ans = 0;
        dfs(root, false);
        return ans;
    }
};
