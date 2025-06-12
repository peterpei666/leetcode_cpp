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
    int sz;
    
    int dfs(TreeNode* node,int list[]) //use bitmask
    {
        if(node==nullptr)
        {
            return 1;
        }
        int l=dfs(node->left,list);
        int r=dfs(node->right,list);
        if((l&1)&&(r&1)&&(l>>1)==(r>>1))
        {
            int sum=(l>>1)+(r>>1)+1;
            list[sz]=sum;
            sz++;
            return (sum<<1)+1;
        }
        return 0;
    }
    
public:
    int kthLargestPerfectSubtree(TreeNode* root, int k)
    {
        sz=0;
        int list[2000];
        dfs(root,list);
        k--;
        if(k>=sz)
        {
            return -1;
        }
        sort(&list[0],&list[0]+sz,greater<>());
        return list[k];
    }
};
