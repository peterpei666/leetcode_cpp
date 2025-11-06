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
    TreeNode* p1 = nullptr;
    TreeNode* p2 = nullptr;
    TreeNode* prev = nullptr;
    
    void find(TreeNode* node)
    {
        if (node == nullptr)
        {
            return;
        }
        find(node->left);
        if (prev && node->val < prev->val)
        {
            if (p1 == nullptr)
            {
                p1 = prev;
            }
            p2 = node;
        }
        prev = node;
        find(node->right);
    }
    
public:
    void recoverTree(TreeNode* root)
    {
        find(root);
        swap(p1->val, p2->val);
    }
};
