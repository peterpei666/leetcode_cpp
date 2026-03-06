#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    struct TrieNode
    {
        int cnt;
        TrieNode* children[2];

        TrieNode()
        {
            cnt = 0;
            memset(this->children, 0, sizeof(children));
        }
    };
    
    TrieNode* root;
    
    void add(int x)
    {
        TrieNode* node = root;
        for (int i = 30; i >= 0; i--)
        {
            if (x & (1 << i))
            {
                if (!node->children[1])
                {
                    node->children[1] = new TrieNode();
                }
                node = node->children[1];
            }
            else
            {
                if (!node->children[0])
                {
                    node->children[0] = new TrieNode();
                }
                node = node->children[0];
            }
            node->cnt++;
        }
    }
    
    int dfs(int x, int bound, int cur, TrieNode* node, int bit)
    {
        if (!node)
        {
            return 0;
        }
        if (bit == -1)
        {
            return node->cnt;
        }
        if ((cur + (1 << bit)) > bound)
        {
            if (x & (1 << bit))
            {
                return dfs(x, bound, cur, node->children[1], bit - 1);
            }
            else
            {
                return dfs(x, bound, cur, node->children[0], bit - 1);
            }
        }
        if ((cur + (1 << (bit + 1))) <= bound)
        {
            return node->cnt;
        }
        if (x & (1 << bit))
        {
            return dfs(x, bound, cur, node->children[1], bit - 1) + dfs(x, bound, cur | (1 << bit), node->children[0], bit - 1);
        }
        else
        {
            return dfs(x, bound, cur, node->children[0], bit - 1) + dfs(x, bound, cur | (1 << bit), node->children[1], bit - 1);
        }
    }
    
public:
    int countPairs(vector<int>& nums, int low, int high)
    {
        int ans = 0;
        root = new TrieNode();
        for (int i : nums)
        {
            ans += dfs(i, high, 0, root, 30) - dfs(i, low - 1, 0, root, 30);
            add(i);
        }
        return ans;
    }
};
