#include <iostream>
#include <algorithm>
#include <deque>
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
    int maxXor(vector<int>& nums, int k)
    {
        deque<int> q1;
        deque<int> q2;
        root = new TrieNode();
        add(0);
        int ans = 0;
        int n = (int)nums.size();
        vector<int> pre(n);
        pre[0] = nums[0];
        for (int i = 1; i < n; i++)
        {
            pre[i] = pre[i - 1] ^ nums[i];
        }
        for (int i = 0, j = 0; i < n; i++)
        {
            while (!q1.empty() && q1.back() < nums[i])
            {
                q1.pop_back();
            }
            q1.push_back(nums[i]);
            while (!q2.empty() && q2.back() > nums[i])
            {
                q2.pop_back();
            }
            q2.push_back(nums[i]);
            while (q1.front() - q2.front() > k)
            {
                if (nums[j] == q1.front())
                {
                    q1.pop_front();
                }
                if (nums[j] == q2.front())
                {
                    q2.pop_front();
                }
                remove(j ? pre[j - 1] : 0);
                j++;
            }
            ans = max(ans, get(pre[i]));
            add(pre[i]);
        }
        return ans;
    }
};
