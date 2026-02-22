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
    int findMaximumXOR(vector<int>& nums)
    {
        root = new TrieNode();
        for (int i : nums)
        {
            add(i);
        }
        int ans = 0;
        for (int i : nums)
        {
            ans = max(ans, get(i));
        }
        return ans;
    }
};
