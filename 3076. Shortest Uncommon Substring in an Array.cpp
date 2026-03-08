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
    
    TrieNode* root;
    
    void add(const string& s, int i, int j)
    {
        TrieNode* temp = root;
        for (; i < j; i++)
        {
            if (temp->child[s[i] - 'a'] == nullptr)
            {
                temp->child[s[i] - 'a'] = new TrieNode();
            }
            temp = temp->child[s[i] - 'a'];
            temp->cnt++;
        }
    }
    
    bool get(const string& s, int i, int j)
    {
        TrieNode* temp = root;
        for (; i < j; i++)
        {
            if (temp->child[s[i] - 'a']->cnt == 0)
            {
                break;
            }
            temp = temp->child[s[i] - 'a'];
        }
        return i != j;
    }
    
    void remove(const string& s, int i, int j)
    {
        TrieNode* temp = root;
        for (; i < j; i++)
        {
            temp = temp->child[s[i] - 'a'];
            temp->cnt--;
        }
    }
    
public:
    vector<string> shortestSubstrings(vector<string>& arr)
    {
        root = new TrieNode();
        for (auto& s : arr)
        {
            int n = (int)s.size();
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    add(s, i, j);
                }
            }
        }
        vector<string> ans;
        for (auto& s : arr)
        {
            int n = (int)s.size();
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    remove(s, i, j);
                }
            }
            string ret = "zzzzzzzzzzzzzzzzzzzzzzzzz";
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    if (get(s, i, j))
                    {
                        if (j - i < ret.size() || (j - i <= ret.size() && s.substr(i, j - i) < ret))
                        {
                            ret = s.substr(i, j - i);
                        }
                    }
                }
            }
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j <= n; j++)
                {
                    add(s, i, j);
                }
            }
            ans.push_back(ret == "zzzzzzzzzzzzzzzzzzzzzzzzz" ? "" : ret);
        }
        return ans;
    }
};
