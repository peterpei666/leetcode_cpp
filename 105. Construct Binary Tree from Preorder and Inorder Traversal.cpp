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
    int n, idx;
    unordered_map<int, int> mp;
    
    TreeNode* build(vector<int>& preorder, int l, int r)
    {
        if (l > r)
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(preorder[idx]);
        idx++;
        root->left = build(preorder, l, mp[root->val] - 1);
        root->right = build(preorder, mp[root->val] + 1, r);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
    {
        mp.clear();
        n = (int)inorder.size();
        idx = 0;
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
        return build(preorder, 0, n - 1);
    }
};
