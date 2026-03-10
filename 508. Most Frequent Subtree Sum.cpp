#include <iostream>
#include <algorithm>
#include <unordered_map>
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
    int dfs(unordered_map<int, int>& mp, TreeNode* node)
    {
        if (node == nullptr)
        {
            return 0;
        }
        int total = node->val + dfs(mp, node->left) + dfs(mp, node->right);
        mp[total]++;
        return total;
    }
    
public:
    vector<int> findFrequentTreeSum(TreeNode* root)
    {
        unordered_map<int, int> mp;
        dfs(mp, root);
        int cur = 0;
        vector<int> ans;
        for (auto [x, n] : mp)
        {
            if (n > cur)
            {
                ans = vector<int>();
                cur = n;
            }
            if (n == cur)
            {
                ans.push_back(x);
            }
        }
        return ans;
    }
};
