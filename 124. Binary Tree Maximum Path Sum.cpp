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
    int maxPathSum(TreeNode* root)
    {
        int ans=INT_MIN;
        
        function<int(TreeNode*)> dfs=[&](TreeNode* node) -> int
        {
            if(node==nullptr)
            {
                return 0;
            }
            int l=dfs(node->left);
            int r=dfs(node->right);
            ans=max(ans,node->val+max(0,l)+max(0,r));
            return max(0,node->val+max(0,max(l,r)));
        };
        
        dfs(root);
        return ans;
    }
};
