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
    int cnt;
    
    void dfs(TreeNode* node,int cur)
    {
        if(node->val>=cur)
        {
            cur=node->val;
            cnt++;
        }
        if(node->left)
        {
            dfs(node->left,cur);
        }
        if(node->right)
        {
            dfs(node->right,cur);
        }
    }
    
public:
    int goodNodes(TreeNode* root)
    {
        cnt=0;
        if(root)
        {
            dfs(root,INT_MIN);
        }
        return cnt;
    }
};
