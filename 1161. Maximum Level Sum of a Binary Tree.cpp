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
    int maxLevelSum(TreeNode* root)
    {
        int num[100000] = {0};
        int depth = 0;
        
        function<void(TreeNode*, int)> dfs = [&](TreeNode* node, int d)
        {
            if (node)
            {
                depth = max(depth, d);
                num[d] += node->val;
                dfs(node->left, d + 1);
                dfs(node->right, d + 1);
            }
        };
        
        dfs(root, 0);
        int ans = 0;
        for (int i = 1; i <= depth; i++)
        {
            if (num[i] > num[ans])
            {
                ans = i;
            }
        }
        return ans + 1;
    }
};
