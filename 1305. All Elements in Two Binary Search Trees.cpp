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
    void inorder(TreeNode* node,vector<int>& list)
    {
        if(node->left)
        {
            inorder(node->left,list);
        }
        list.push_back(node->val);
        if(node->right)
        {
            inorder(node->right,list);
        }
    }
    
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int> list;
        if(root1)
        {
            inorder(root1,list);
        }
        if(root2)
        {
            inorder(root2,list);
        }
        sort(list.begin(),list.end());
        return list;
    }
};
