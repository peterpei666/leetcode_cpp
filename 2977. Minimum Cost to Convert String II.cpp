#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

#define ull unsigned long long
class Solution
{
public:
    long long minimumCost(string source, string target, vector<string>& original, vector<string>& changed, vector<int>& cost)
    {
        const ull inf = ULLONG_MAX;
        ull dist[201][201];
        ull dp[1001];
        unordered_map<string, int> id;
        unordered_set<int> len;
        int m = (int)original.size();
        int n = (int)source.size();
        int sz = 0;
        memset(dist, -1, sizeof(dist));
        for (int i = 0; i < m; i++)
        {
            if (!id.count(original[i]))
            {
                id[original[i]] = sz;
                sz++;
                len.insert((int)original[i].size());
            }
            if (!id.count(changed[i]))
            {
                id[changed[i]] = sz;
                sz++;
            }
            dist[id[original[i]]][id[changed[i]]] = min(dist[id[original[i]]][id[changed[i]]], (ull)cost[i]);
        }
        for (int i = 0; i < sz; i++)
        {
            dist[i][i] = 0;
        }
        for (int k = 0; k < sz; k++)
        {
            for (int i = 0; i < sz; i++)
            {
                if (dist[i][k] != inf)
                {
                    for (int j = 0; j < sz; j++)
                    {
                        if (dist[k][j] != inf)
                        {
                            dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                        }
                    }
                }
            }
        }
        memset(dp, -1, sizeof(dp));
        dp[0] = 0;
        for (int i = 0; i < n; i++)
        {
            if (dp[i] == inf)
            {
                continue;
            }
            if (source[i] == target[i])
            {
                dp[i + 1] = min(dp[i + 1], dp[i]);
            }
            for (int l : len)
            {
                if (i + l <= n)
                {
                    string u = source.substr(i, l);
                    string v = target.substr(i, l);
                    if (id.count(u) && id.count(v) && dist[id[u]][id[v]] != inf)
                    {
                        dp[i + l] = min(dp[i + l], dp[i] + dist[id[u]][id[v]]);
                    }
                }
            }
        }
        return dp[n] == inf ? -1 : dp[n];
    }
};
