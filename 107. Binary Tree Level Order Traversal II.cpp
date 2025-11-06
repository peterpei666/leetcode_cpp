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
    int depth(TreeNode* node, int cur)
    {
        if (node == nullptr)
        {
            return cur;
        }
        return max(depth(node->left, cur + 1), depth(node->right, cur + 1));
    }
    
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root)
    {
        vector<vector<int>> ans(depth(root, 0));
        
        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int d)
        {
            if (!node)
            {
                return;
            }
            ans[d].push_back(node->val);
            dfs(node->left, d + 1);
            dfs(node->right, d + 1);
        };
        
        dfs(root, 0);
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
