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
    void construct(TreeNode* node,string& ret)
    {
        if(node==nullptr)
        {
            ret+=")";
            return;
        }
        ret+=to_string(node->val);
        if(node->left||node->right)
        {
            ret+="(";
            construct(node->left,ret);
            if(node->right)
            {
                ret+="(";
                construct(node->right,ret);
            }
            ret+=")";
        }
        else
        {
            ret+=")";
        }
    }
    
public:
    string tree2str(TreeNode* root)
    {
        string ret="";
        construct(root,ret);
        ret.pop_back();
        return ret;
    }
};
