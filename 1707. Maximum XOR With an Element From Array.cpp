#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    struct TrieNode
    {
        TrieNode* children[2];

        TrieNode()
        {
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
        }
    }
    
    int get(int x)
    {
        TrieNode* node = root;
        int ans = 0;
        for (int i = 30; i >= 0; i--)
        {
            if (!node->children[0] && !node->children[1])
            {
                return -1;
            }
            if (x & (1 << i))
            {
                if (node->children[0])
                {
                    ans |= 1 << i;
                    node = node->children[0];
                }
                else
                {
                    node = node->children[1];
                }
            }
            else
            {
                if (node->children[1])
                {
                    ans |= 1 << i;
                    node = node->children[1];
                }
                else
                {
                    node = node->children[0];
                }
            }
        }
        return ans;
    }
    
public:
    vector<int> maximizeXor(vector<int>& nums, vector<vector<int>>& queries)
    {
        int m = (int)nums.size();
        int n = (int)queries.size();
        vector<pair<vector<int>, int>> p(n);
        for (int i = 0; i < n; i++)
        {
            p[i] = make_pair(queries[i], i);
        }
        sort(nums.begin(), nums.end());
        sort(p.begin(), p.end(), [&](const pair<vector<int>, int>& a, const pair<vector<int>, int>& b) {
            return a.first[1] < b.first[1];
        });
        vector<int> ans(n);
        root = new TrieNode();
        for (int i = 0, j = 0; i < n; i++)
        {
            while (j < m && nums[j] <= p[i].first[1])
            {
                add(nums[j]);
                j++;
            }
            ans[p[i].second] = get(p[i].first[0]);
        }
        return ans;
    }
};
