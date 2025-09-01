#include <iostream>
#include <algorithm>
using namespace std;

struct Fenwick
{
    int n;
    vector<long long> list;
    
    Fenwick(int n) : n(n + 1), list(n + 1, 0) {}
    
    long long sum(int i)
    {
        long long ans = 0;
        while (i > 0)
        {
            ans += list[i];
            i -= i & -i;
        }
        return ans;
    }
    
    void add(int i, int x)
    {
        while (i < n)
        {
            list[i] += x;
            i += i & -i;
        }
    }
};

class Solution
{
public:
    int totalBeauty(vector<int>& nums)
    {
        const int mod = 1e9 + 7;
        int m = *max_element(nums.begin(), nums.end()) + 1;
        unordered_map<int, vector<int>> mp;
        int n = (int)nums.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }
        vector<long long> f(m, 0);
        for (int d = 1; d < m; d++)
        {
            vector<int> temp;
            for (int v = d; v < m; v += d)
            {
                if (!mp.count(v))
                {
                    continue;
                }
                for (int p : mp[v])
                {
                    temp.push_back(p);
                }
            }
            if (temp.size() <= 1)
            {
                f[d] = temp.size();
                continue;
            }
            sort(temp.begin(), temp.end());
            unordered_map<int, int> rank;
            int sz = (int)temp.size();
            for (int r = 0; r < sz; r++)
            {
                rank[temp[r]] = r + 1;
            }
            Fenwick fen(sz);
            for (int v = d; v < m; v += d)
            {
                if (!mp.count(v))
                {
                    continue;
                }
                for (auto it = mp[v].rbegin(); it != mp[v].rend(); it++)
                {
                    int p = *it;
                    int r = rank[p];
                    long long addend = 1 + fen.sum(r - 1);
                    f[d] = (f[d] + addend) % mod;
                    fen.add(r, addend % mod);
                }
            }
        }
        for (int d = m - 1; d >= 1; d--)
        {
            for (int e = 2 * d; e < m; e += d)
            {
                f[d] = (f[d] - f[e] + mod) % mod;
            }
        }
        long long ans = 0;
        for (int d = 1; d < m; d++)
        {
            ans = (ans + 1LL * d % mod * f[d] % mod) % mod;
        }
        return ans % mod;
    }
};
