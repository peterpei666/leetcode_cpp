#include <iostream>
#include <algorithm>
#include <unordered_map>
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
private:
    TreeNode* build(vector<int>& nums, int l, int r)
    {
        if (l > r)
        {
            return nullptr;
        }
        int mid = (l + r) / 2;
        TreeNode* node = new TreeNode(nums[mid]);
        node->left = build(nums, l, mid - 1);
        node->right = build(nums, mid + 1, r);
        return node;
    }
    
public:
    TreeNode* sortedListToBST(ListNode* head)
    {
        vector<int> nums;
        while (head)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        return build(nums, 0, (int)nums.size() - 1);
    }
};
