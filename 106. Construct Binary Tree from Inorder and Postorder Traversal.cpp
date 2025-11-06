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
    
    TreeNode* build(vector<int>& postorder, int l, int r)
    {
        if (l > r)
        {
            return nullptr;
        }
        TreeNode* root = new TreeNode(postorder[idx]);
        idx--;
        root->right = build(postorder, mp[root->val] + 1, r);
        root->left = build(postorder, l, mp[root->val] - 1);
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder)
    {
        mp.clear();
        n = (int)inorder.size();
        idx = n - 1;
        for (int i = 0; i < n; i++)
        {
            mp[inorder[i]] = i;
        }
        return build(postorder, 0, n - 1);
    }
};
