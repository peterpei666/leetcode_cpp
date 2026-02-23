#include <iostream>
#include <algorithm>
#include <sstream>
using namespace std;

class Solution
{
private:
    struct TrieNode
    {
        TrieNode* children[26] = {};
        bool tag = false;
    };
    
    void free(TrieNode* node)
    {
        if (!node) return;
        for (int i = 0; i < 26; ++i)
        {
            free(node->children[i]);
        }
        delete node;
    }

public:
    string replaceWords(vector<string>& dictionary, const string& sentence)
    {
        TrieNode* root = new TrieNode();
        for (const string& w : dictionary)
        {
            TrieNode* node = root;
            for (char c : w)
            {
                int i = c - 'a';
                if (!node->children[i])
                {
                    node->children[i] = new TrieNode();
                }
                node = node->children[i];
            }
            node->tag = true;
        }
        string ans;
        stringstream ss(sentence);
        string word;
        bool first = true;
        while (ss >> word)
        {
            if (!first)
            {
                ans += " ";
            }
            first = false;
            TrieNode* node = root;
            string prefix;
            bool replaced = false;
            for (char c : word)
            {
                int i = c - 'a';
                if (!node->children[i])
                {
                    break;
                }
                node = node->children[i];
                prefix += c;
                if (node->tag)
                {
                    ans += prefix;
                    replaced = true;
                    break;
                }
            }
            if (!replaced)
            {
                ans += word;
            }
        }
        free(root);
        return ans;
    }
};
