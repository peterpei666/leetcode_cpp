#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    struct TrieNode
    {
        TrieNode* child[26];
        int cnt;
        
        TrieNode() { memset(child, 0, sizeof(child)); cnt = 0; }
    };
    
    int n;
    TrieNode* root;
    
    void add(const string& s)
    {
        TrieNode* temp = root;
        for (const char& c : s)
        {
            if (temp->child[c - 'a'] == nullptr)
            {
                temp->child[c - 'a'] = new TrieNode();
            }
            temp = temp->child[c - 'a'];
            temp->cnt++;
        }
    }
    
    int get(const string& s)
    {
        int ans = 0;
        TrieNode* temp = root;
        for (const char& c : s)
        {
            if (temp->child[c - 'a'] == nullptr)
            {
                break;
            }
            temp = temp->child[c - 'a'];
            ans += temp->cnt;
        }
        return ans;
    }
    
public:
    vector<int> sumPrefixScores(vector<string>& words)
    {
        root = new TrieNode();
        for (auto& s : words)
        {
            add(s);
        }
        vector<int> ans;
        for (string s : words)
        {
            ans.push_back(get(s));
        }
        return ans;
    }
};
