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

class Solution {
public:
    int left=0,right=0;

    int count(TreeNode* node,int x)
    {
        if(node==NULL)
        {
            return 0;
        }
        int l,r;
        l=count(node->left,x);
        r=count(node->right,x);
        if(node->val==x)
        {
            left=l;
            right=r;
        }
        return l+r+1;
    }
    
    bool btreeGameWinningMove(TreeNode* root, int n, int x)
    {
        int m=0;
        count(root,x);
        return max(max(left,right),n-left-right-1)>n/2;
    }
};
