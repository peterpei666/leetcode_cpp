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
    vector<int> postorderTraversal(TreeNode* root)
    {
        vector<int> ans;
        
        function<void(TreeNode*)> postorder = [&](TreeNode* node)
        {
            if (node == nullptr)
            {
                return;
            }
            postorder(node->left);
            postorder(node->right);
            ans.push_back((node->val));
        };
        
        postorder(root);
        return ans;
    }
};
