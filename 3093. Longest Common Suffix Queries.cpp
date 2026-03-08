#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    static const int M = 500005;
    int trie[M][26];
    int id[M];
    int sz[M];
    int cnt;
    
    void add(const string& s, int idx)
    {
        int cur = 0;
        int n = (int)s.size();
        if (n < sz[cur])
        {
            sz[cur] = n;
            id[cur] = idx;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            int c = s[i] - 'a';
            if (trie[cur][c] == 0)
            {
                memset(trie[cnt], 0, sizeof(trie[cnt]));
                trie[cur][c] = cnt++;
            }
            cur = trie[cur][c];
            if (n < sz[cur])
            {
                sz[cur] = n;
                id[cur] = idx;
            }
        }
    }
    
    int query(const string& s)
    {
        int cur = 0;
        int n = (int)s.size();
        for (int i = n - 1; i >= 0; i--)
        {
            int c = s[i] - 'a';
            if (trie[cur][c] == 0)
            {
                break;
            }
            cur = trie[cur][c];
        }
        return id[cur];
    }
    
public:
    vector<int> stringIndices(vector<string>& wordsContainer, vector<string>& wordsQuery)
    {
        memset(trie[0], 0, sizeof(trie[0]));
        memset(id, -1, sizeof(id));
        memset(sz, 0x7f, sizeof(sz));
        cnt = 1;
        int n = (int)wordsContainer.size();
        for (int i = 0; i < n; i++)
        {
            add(wordsContainer[i], i);
        }
        n = (int)wordsQuery.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = query(wordsQuery[i]);
        }
        return ans;
    }
};
