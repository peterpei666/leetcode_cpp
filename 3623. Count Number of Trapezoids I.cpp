#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int countTrapezoids(vector<vector<int>>& points)
    {
        unordered_map<int, int> mp;
        for (auto& p : points)
        {
            mp[p[1]]++;
        }
        long long total = 0;
        for (auto [_, n] : mp)
        {
            total += 1LL * n * (n - 1) / 2;
        }
        long long ans = 0;
        const int mod = 1e9 + 7;
        for (auto [_, n] : mp)
        {
            ans += (1LL * n * (n - 1) / 2) * (total - 1LL * n * (n - 1) / 2) % mod;
        }
        if (ans & 1)
        {
            return (ans + mod) / 2 % mod;
        }
        return ans / 2 % mod;
    }
};
