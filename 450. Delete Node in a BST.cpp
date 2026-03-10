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
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if (root == nullptr)
        {
            return nullptr;
        }
        if (key < root->val)
        {
            root->left = deleteNode(root->left, key);
        }
        else if (key > root->val)
        {
            root->right = deleteNode(root->right, key);
        }
        else
        {
            if (root->left == nullptr && root->right == nullptr)
            {
                return nullptr;
            }
            if (root->left == nullptr || root->right == nullptr)
            {
                return root->left == nullptr ? root->right : root->left;
            }
            TreeNode* temp = root->left;
            while (temp->right)
            {
                temp = temp->right;
            }
            root->val = temp->val;
            root->left = deleteNode(root->left, temp->val);
        }
        return root;
    }
};
