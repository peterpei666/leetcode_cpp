#include <iostream>
#include <algorithm>
using namespace std;

class Node
{
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution
{
private:
    int depth(Node* node, int cur)
    {
        if (node == nullptr)
        {
            return cur;
        }
        return max(depth(node->left, cur + 1), depth(node->right, cur + 1));
    }
    
public:
    Node* connect(Node* root)
    {
        vector<vector<Node*>> layer(depth(root, 0));
        
        function<void(Node*, int)> dfs = [&](Node* node, int depth)
        {
            if (node)
            {
                layer[depth].push_back(node);
                dfs(node->left, depth + 1);
                dfs(node->right, depth + 1);
            }
        };
        
        dfs(root, 0);
        for (auto& l : layer)
        {
            int n = (int)l.size();
            for (int i = 1; i < n; i++)
            {
                l[i - 1]->next = l[i];
            }
        }
        return root;
    }
};
