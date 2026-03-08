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
    
    int get(int x) {
        TrieNode* node = root;
        int ans = 0;
        for (int i = 30; i >= 0; i--)
        {
            if (!node)
            {
                return -1;
            }
            int bit = (x >> i) & 1;
            int target = 1 - bit;
            if (node->children[target] && node->children[target]->cnt > 0)
            {
                ans |= (1 << i);
                node = node->children[target];
            }
            else if (node->children[bit] && node->children[bit]->cnt > 0)
            {
                node = node->children[bit];
            }
            else
            {
                return -1;
            }
        }
        return ans;
    }

    void remove(int x)
    {
        TrieNode* node = root;
        for (int i = 30; i >= 0; i--)
        {
            int bit = (x >> i) & 1;
            node = node->children[bit];
            node->cnt--;
        }
    }
    
public:
    vector<int> maxGeneticDifference(vector<int>& parents, vector<vector<int>>& queries)
    {
        int n = (int)parents.size();
        vector<vector<int>> graph(n);
        int start = -1;
        for (int i = 0; i < n; i++)
        {
            if (parents[i] == -1)
            {
                start = i;
            }
            else
            {
                graph[parents[i]].push_back(i);
            }
        }
        int q = (int)queries.size();
        unordered_map<int, vector<pair<int, int>>> query;
        for (int i = 0; i < q; i++)
        {
            query[queries[i][0]].push_back(make_pair(i, queries[i][1]));
        }
        root = new TrieNode();
        vector<int> ans(q);
        
        function<void(int)> dfs = [&](int cur)
        {
            add(cur);
            if (query.count(cur))
            {
                for (auto [i, x] : query[cur])
                {
                    ans[i] = get(x);
                }
            }
            for (int next : graph[cur])
            {
                dfs(next);
            }
            remove(cur);
        };
        
        dfs(start);
        return ans;
    }
};
