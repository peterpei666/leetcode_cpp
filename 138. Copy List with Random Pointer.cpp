#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node* copyRandomList(Node* head)
    {
        unordered_map<Node*, Node*> memo;
        memo[nullptr] = nullptr;
        
        function<Node*(Node*)> build = [&](Node* node) -> Node*
        {
            if (memo.count(node))
            {
                return memo[node];
            }
            memo[node] = new Node(node->val);
            memo[node]->next = build(node->next);
            memo[node]->random = build(node->random);
            return memo[node];
        };
        
        return build(head);
    }
};
