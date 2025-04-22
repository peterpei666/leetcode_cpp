#include <iostream>
#include <algorithm>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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
    bool match(ListNode* head, TreeNode* node)
    {
        if(node==nullptr)
        {
            return false;
        }
        if(node->val==head->val)
        {
            if(head->next==nullptr)
            {
                return true;
            }
            else
            {
                return match(head->next,node->left)||match(head->next,node->right);
            }
        }
        return false;
    }
    
    bool isSubPath(ListNode* head, TreeNode* root)
    {
        if(root==nullptr)
        {
            return false;
        }
        return match(head,root)||isSubPath(head,root->left)||isSubPath(head,root->right);
    }
};
