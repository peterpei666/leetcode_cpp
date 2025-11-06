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
    vector<int> inorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        
        function<void(TreeNode*)> inorder = [&](TreeNode* node)
        {
            if (node == nullptr)
            {
                return;
            }
            inorder(node->left);
            ans.push_back(node->val);
            inorder(node->right);
        };
        
        inorder(root);
        return ans;
    }
};
