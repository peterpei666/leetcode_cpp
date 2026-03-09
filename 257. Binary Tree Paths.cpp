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
    void dfs(string temp, TreeNode* node, vector<string>& ans)
    {
        if (node == nullptr)
        {
            return;
        }
        if (temp.size())
        {
            temp += "->";
        }
        temp += to_string(node->val);
        if (node->left == nullptr && node->right == nullptr)
        {
            ans.push_back(temp);
            return;
        }
        dfs(temp, node->left, ans);
        dfs(temp, node->right, ans);
    }
    
public:
    vector<string> binaryTreePaths(TreeNode* root)
    {
        vector<string> ans;
        dfs("", root, ans);
        return ans;
    }
};
