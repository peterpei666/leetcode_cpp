#include <iostream>
#include <algorithm>
using namespace std;

class Trie
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
    
public:
    Trie()
    {
        root = new TrieNode();
    }
    
    void insert(const string& word)
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
        TrieNode* node = root;
        for (char c : word)
        {
            if (node->children[c - 'a'] == nullptr)
            {
                return false;
            }
            node = node->children[c - 'a'];
        }
        return node->tag;
    }
    
    bool startsWith(const string& prefix)
    {
        TrieNode* node = root;
        for (char c : prefix)
        {
            if (node->children[c - 'a'] == nullptr)
            {
                return false;
            }
            node = node->children[c - 'a'];
        }
        return true;
    }
};
