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

class MagicDictionary
{
private:
    struct TrieNode
    {
        TrieNode* children[26];
        bool tag;
        
        TrieNode()
        {
            memset(this->children, 0, sizeof(children));
            tag = false;
        }
    };
    
    TrieNode* root;

    bool dfs(TrieNode* node, const string& word, int idx, bool change)
    {
        if (node == nullptr)
        {
            return false;
        }
        if (idx == word.size())
        {
            return node->tag && change;
        }
        if (change)
        {
            return dfs(node->children[word[idx] - 'a'], word, idx + 1, change);
        }
        bool ans = dfs(node->children[word[idx] - 'a'], word, idx + 1, false);
        for (int i = 0; i < 26 && !ans; i++)
        {
            if (i != word[idx] - 'a')
            {
                ans |= dfs(node->children[i], word, idx + 1, true);
            }
        }
        return ans;
    }
    
public:
    MagicDictionary() {
        root = new TrieNode();
    }
    
    void buildDict(vector<string> dictionary)
    {
        for (auto& word : dictionary)
        {
            TrieNode* node = root;
            for (char c : word)
            {
                if (node->children[c - 'a'] == nullptr)
                {
                    node->children[c - 'a'] = new TrieNode();
                }
                node = node->children[c - 'a'];
            }
            node->tag = true;
        }
    }
    
    bool search(const string& word)
    {
        return dfs(root, word, 0, false);
    }
};
