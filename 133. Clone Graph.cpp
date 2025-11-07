#include <iostream>
#include <algorithm>
using namespace std;

class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution
{
public:
    Node* cloneGraph(Node* node)
    {
        Node* memo[101];
        memset(memo, 0, sizeof(memo));
        
        function<Node*(Node*)> dfs = [&](Node* node) -> Node*
        {
            if (memo[node->val])
            {
                return memo[node->val];
            }
            memo[node->val] = new Node(node->val);
            for (auto next : node->neighbors)
            {
                memo[node->val]->neighbors.push_back(dfs(next));
            }
            return memo[node->val];
        };
        
        if (!node)
        {
            return nullptr;
        }
        dfs(node);
        return memo[node->val];
    }
};
