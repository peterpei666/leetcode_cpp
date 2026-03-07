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
    int maximumStrongPairXor(vector<int>& nums)
    {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        int ans = 0;
        root = new TrieNode();
        for (int i = 0, j = 0; i < n; i++)
        {
            while (nums[i] > 2 * nums[j])
            {
                remove(nums[j]);
                j++;
            }
            add(nums[i]);
            ans = max(ans, get(nums[i]));
        }
        return ans;
    }
};
