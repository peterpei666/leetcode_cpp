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
    void dfs(TreeNode* node,int depth,vector<vector<int>>& list)
    {
        if(node==nullptr)
        {
            return;
        }
        if(depth==list.size())
        {
            list.push_back({});
        }
        list[depth].push_back(node->val);
        dfs(node->left,depth+1,list);
        dfs(node->right,depth+1,list);
    }
    
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root)
    {
        vector<vector<int>> list;
        dfs(root,0,list);
        for(int i=0;i<list.size();i++)
        {
            if(i%2)
            {
                reverse(list[i].begin(),list[i].end());
            }
        }
        return list;
    }
};
