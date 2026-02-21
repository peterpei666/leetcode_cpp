#include <iostream>
#include <algorithm>
using namespace std;

class WordDictionary
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
    
    bool search(TrieNode* node, const string& word, int idx)
    {
        if (idx == word.size())
        {
            return node->tag;
        }
        if (word[idx] == '.')
        {
            bool ans = false;
            for (int i = 0; i < 26 && !ans; i++)
            {
                if (node->children[i])
                {
                    ans = search(node->children[i], word, idx + 1);
                }
            }
            return ans;
        }
        if (node->children[word[idx] - 'a'])
        {
            return search(node->children[word[idx] - 'a'], word, idx + 1);
        }
        return false;
    }
    
public:
    WordDictionary()
    {
        root = new TrieNode();
    }
    
    void addWord(const string& word)
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
    
    bool search(const string& word)
    {
        return search(root, word, 0);
    }
};
