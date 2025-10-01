#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct node
{
    node* children[27];
    int idx;
    
    node()
    {
        idx = -1;
        memset(children, 0, sizeof(children));
    }
    
    ~node()
    {
        for (int i = 0; i < 27; i++)
        {
            if (children[i] != nullptr)
            {
                delete children[i];
            }
        }
    }
};

class WordFilter
{
private:
    node* root;
    
public:
    WordFilter(vector<string>& words)
    {
        root = new node();
        int n = (int)words.size();
        for (int i = 0; i < n; i++)
        {
            int l = (int)words[i].size();
            for (int j = 0; j <= l; j++)
            {
                node* cur = root;
                string temp = words[i].substr(j) + "{" + words[i];
                for (char c : temp)
                {
                    if (cur->children[c - 'a'] == nullptr)
                    {
                        cur->children[c - 'a'] = new node();
                    }
                    cur = cur->children[c - 'a'];
                    cur->idx = i;
                }
            }
        }
    }
    
    int f(const string& pref, const string& suff)
    {
        node* cur = root;
        string word = suff + "{" + pref;
        for (char c : word)
        {
            if (cur->children[c - 'a'] == nullptr)
            {
                return -1;
            }
            cur = cur->children[c - 'a'];
        }
        return cur->idx;
    }
    
    ~WordFilter()
    {
        delete root;
    }
};
