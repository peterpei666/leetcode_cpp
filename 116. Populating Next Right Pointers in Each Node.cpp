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
public:
    Node* connect(Node* root)
    {
        int cnt[12] = {0};
        Node* layer[12][2048];
        
        function<void(Node*, int)> dfs = [&](Node* node, int depth)
        {
            if (node)
            {
                layer[depth][cnt[depth]] = node;
                cnt[depth]++;
                dfs(node->left, depth + 1);
                dfs(node->right, depth + 1);
            }
        };
        
        dfs(root, 0);
        for (int i = 1; i < 12; i++)
        {
            for (int j = 1; j < cnt[i]; j++)
            {
                layer[i][j - 1]->next = layer[i][j];
            }
        }
        return root;
    }
};
