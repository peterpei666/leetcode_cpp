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
    int ans;
    
    int dfs(TreeNode* node,int start)
    {
        int depth=0;
        if(node==nullptr)
        {
            return depth;
        }
        int l=dfs(node->left,start);
        int r=dfs(node->right,start);
        if(node->val==start)
        {
            ans=max(l,r);
            return -1;
        }
        if(l>=0&&r>=0)
        {
            depth=max(l,r)+1;
        }
        else
        {
            int dis=abs(l)+abs(r);
            ans=max(ans,dis);
            depth=min(l,r)-1;
        }
        return depth;
    }
    
public:
    int amountOfTime(TreeNode* root, int start)
    {
        ans=0;
        dfs(root,start);
        return ans;
    }
};
