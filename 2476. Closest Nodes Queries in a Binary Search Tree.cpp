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
    vector<vector<int>> closestNodes(TreeNode* root, vector<int>& queries)
    {
        vector<int> mp;
        
        function<void(TreeNode*)> dfs = [&](TreeNode* node)
        {
            if (node)
            {
                dfs(node->left);
                mp.push_back(node->val);
                dfs(node->right);
            }
        };
        
        dfs(root);
        vector<vector<int>> ans;
        for (const int& q : queries)
        {
            auto p = lower_bound(mp.begin(), mp.end(), q);
            if (p != mp.end() && *p == q)
            {
                ans.push_back({q, q});
            }
            else
            {
                ans.push_back({p == mp.begin() ? -1 : *(p - 1), p == mp.end() ? -1 : *p});
            }
        }
        return ans;
    }
};
