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
    void preorder(TreeNode* node, int d, vector<int>& ans)
    {
        if (node == nullptr)
        {
            return;
        }
        if (d == ans.size())
        {
            ans.push_back(node->val);
        }
        ans[d] = node->val;
        preorder(node->left, d + 1, ans);
        preorder(node->right, d + 1, ans);
    }
    
public:
    vector<int> rightSideView(TreeNode* root)
    {
        vector<int> ans;
        preorder(root, 0, ans);
        return ans;
    }
};
