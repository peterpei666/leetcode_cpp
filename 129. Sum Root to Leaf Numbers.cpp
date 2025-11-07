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
    int sumNumbers(TreeNode* root)
    {
        int ans = 0;
        
        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int cur)
        {
            if (!node ->left && !node->right)
            {
                ans += cur * 10 + node->val;
                return;
            }
            if (node->left)
            {
                dfs(node->left, cur * 10 + node->val);
            }
            if (node->right)
            {
                dfs(node->right, cur * 10 + node->val);
            }
        };
        
        dfs(root, 0);
        return ans;
    }
};
