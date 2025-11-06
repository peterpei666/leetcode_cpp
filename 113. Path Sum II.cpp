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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum)
    {
        if (!root)
        {
            return {};
        }
        vector<vector<int>> ans;
        vector<int> path;
        
        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int cur)
        {
            path.push_back(node->val);
            if (!node->left && !node->right)
            {
                if (cur + node->val == targetSum)
                {
                    ans.push_back(path);
                }
                path.pop_back();
                return;
            }
            if (node->left)
            {
                dfs(node->left, cur + node->val);
            }
            if (node->right)
            {
                dfs(node->right, cur + node->val);
            }
            path.pop_back();
        };
        
        dfs(root, 0);
        return ans;
    }
};
