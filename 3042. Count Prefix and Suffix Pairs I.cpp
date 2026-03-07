#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    struct TrieNode
    {
        int cnt = 0;
        unordered_map<int, TrieNode*> children;
    };
    
public:
    int countPrefixSuffixPairs(vector<string>& words)
    {
        TrieNode* root = new TrieNode();
        int ans = 0;
        for (auto& s : words)
        {
            int n = (int)s.size();
            TrieNode* node = root;
            for (int i = 0; i < n; i++)
            {
                int mask = s[i] * 128 + s[n - i - 1];
                if (!node->children.count(mask))
                {
                    node->children[mask] = new TrieNode();
                }
                node = node->children[mask];
                ans += node->cnt;
            }
            node->cnt++;
        }
        return ans;
    }
};
