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
    void dfs(TreeNode* node,int cur,int& depth,int& ans)
    {
        if(node->left)
        {
            dfs(node->left,cur+1,depth,ans);
        }
        if(cur>depth)
        {
            depth=cur;
            ans=node->val;
        }
        if(node->right)
        {
            dfs(node->right,cur+1,depth,ans);
        }
    }
    
public:
    int findBottomLeftValue(TreeNode* root)
    {
        int depth=0,ans=0;
        dfs(root,1,depth,ans);
        return ans;
    }
};
