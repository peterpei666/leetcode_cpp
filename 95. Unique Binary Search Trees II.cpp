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
public:
    vector<TreeNode*> generateTrees(int n)
    {
        vector<vector<vector<TreeNode*>>> dp(n + 1, vector<vector<TreeNode*>>(n + 1));
        for (int i = 1; i <= n; i++)
        {
            dp[i][i].push_back(new TreeNode(i));
        }
        for (int num = 2; num <= n; num++)
        {
            for (int start = 1; start <= n - num + 1; start++)
            {
                int end = start + num - 1;
                for (int i = start; i <= end; i++)
                {
                    vector<TreeNode*> left = i - 1 >= start ? dp[start][i - 1] : vector<TreeNode*>({nullptr});
                    vector<TreeNode*> right = i + 1 <= end ? dp[i + 1][end] : vector<TreeNode*>({nullptr});
                    for (auto l : left)
                    {
                        for(auto r : right)
                        {
                            TreeNode* root = new TreeNode(i, l, r);
                            dp[start][end].push_back(root);
                        }
                    }
                }
            }
        }
        return dp[1][n];
    }
};
