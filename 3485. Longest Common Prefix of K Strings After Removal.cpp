#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    static const int M = 100005;
    int trie[M][26];
    int count[M];
    int depth[M];
    int cnt;
    int dep_cnt[10001];
    int cur_max;
    
    void change(const string& s, int k, int d)
    {
        int cur = 0;
        for (char c : s)
        {
            if (trie[cur][c - 'a'] == 0)
            {
                memset(trie[cnt], 0, sizeof(trie[cnt]));
                depth[cnt] = depth[cur] + 1;
                trie[cur][c - 'a'] = cnt++;
            }
            cur = trie[cur][c - 'a'];
            update(cur, k, d);
        }
    }
    
    void update(int t, int k, int d)
    {
        int old = count[t];
        count[t] += d;
        int dep = depth[t];
        if (old < k && count[t] >= k)
        {
            if (dep_cnt[dep] == 0)
            {
                cur_max = max(cur_max, dep);
            }
            dep_cnt[dep]++;
        }
        else if (old >= k && count[t] < k)
        {
            dep_cnt[dep]--;
            while (cur_max > 0 && dep_cnt[cur_max] == 0)
            {
                cur_max--;
            }
        }
    }
    
public:
    vector<int> longestCommonPrefix(vector<string>& words, int k)
    {
        int n = (int)words.size();
        cnt = 1;
        cur_max = 0;
        memset(trie[0], 0, sizeof(trie[0]));
        memset(count, 0, sizeof(count));
        memset(depth, 0, sizeof(depth));
        memset(dep_cnt, 0, sizeof(dep_cnt));
        for (int i = 0; i < n; i++)
        {
            change(words[i], k, 1);
        }
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            change(words[i], k, -1);
            ans[i] = cur_max;
            change(words[i], k, 1);
        }
        return ans;
    }
};
