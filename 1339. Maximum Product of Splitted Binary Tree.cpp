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
    const int mod = 1e9 + 7;
    long long ans, total;
    
    int dfs(TreeNode* root, bool compute)
    {
        if (!root)
        {
            return 0;
        }
        int sum = root->val + dfs(root->left, compute) + dfs(root->right, compute);
        if (compute)
        {
            ans = max(ans, (total - sum) * sum);
        }
        return sum;
    }
    
public:
    int maxProduct(TreeNode* root)
    {
        ans = INT_MIN;
        total = dfs(root, false);
        dfs(root, true);
        return ans % mod;
    }
};
