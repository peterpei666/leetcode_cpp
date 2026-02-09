#include <stdio.h>
#include <stdlib.h>

struct TreeNode
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};
 
struct TreeNode* balanceBST(struct TreeNode* root)
{
    struct TreeNode* inorder[10000];
    int idx = 0;
    {
        struct TreeNode* stk[10000];
        int sidx = 0;
        struct TreeNode* cur = root;
        while (sidx || cur)
        {
            while (cur)
            {
                stk[sidx++] = cur;
                cur = cur->left;
            }
            cur = stk[--sidx];
            inorder[idx++] = cur;
            cur = cur->right;
        }
    }
    int stk[10000];
    int pid[10000];
    int sz = 1;
    stk[0] = idx - 1;
    pid[0] = -1;
    int root_idx = 0;
    while (sz)
    {
        sz--;
        int l = stk[sz] / 10001;
        int r = stk[sz] % 10001;
        int p = pid[sz];
        int mid = (l + r) / 2;
        inorder[mid]->left = NULL;
        inorder[mid]->right = NULL;
        if (p == -1)
        {
            root_idx = mid;
        }
        else if (mid < p)
        {
            inorder[p]->left = inorder[mid];
        }
        else
        {
            inorder[p]->right = inorder[mid];
        }
        if (r >= mid + 1)
        {
            stk[sz] = (mid + 1) * 10001 + r;
            pid[sz] = mid;
            sz++;
        }
        if (l <= mid - 1)
        {
            stk[sz] = l * 10001 + mid - 1;
            pid[sz] = mid;
            sz++;
        }
    }
    return inorder[root_idx];
}
