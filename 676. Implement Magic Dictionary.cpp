#include <iostream>
#include <algorithm>
using namespace std;

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
