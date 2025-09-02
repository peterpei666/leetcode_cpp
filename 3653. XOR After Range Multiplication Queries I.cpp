#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    const int mod = 1e9 + 7;
    
    long long qpow(long long base, long long e)
    {
        long long ans = 1;
        base %= mod;
        while (e > 0)
        {
            if (e & 1)
            {
                ans = ans * base % mod;
            }
            base = base * base % mod;
            e >>= 1;
        }
        return ans;
    }
    
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries)
    {
        int n = (int)nums.size();
        int B = max(1, (int)sqrt(n));
        vector<vector<array<int, 4>>> small(B + 1);
        for (auto& q : queries)
        {
            int l = q[0], r = q[1], k = q[2], v = q[3];
            if (k > B)
            {
                for (int i = l; i <= r; i += k)
                {
                    nums[i] = (long long)nums[i] * v % mod;
                }
            }
            else
            {
                small[k].push_back({l, r, k, v});
            }
        }
        for (int k = 1; k <= B; k++)
        {
            if (small[k].empty())
            {
                continue;
            }
            vector<vector<int>> prod(k);
            vector<vector<int>> zero(k);
            for (int rem = 0; rem < k; rem++)
            {
                int l = 0;
                if (rem < n)
                {
                    l = (n - 1 - rem) / k + 1;
                }
                prod[rem].assign(l + 1, 1);
                zero[rem].assign(l + 1, 0);
            }
            for (auto& arr : small[k])
            {
                int l = arr[0], r = arr[1], v = arr[3];
                int rem = l % k;
                int j0 = (l - rem) / k;
                int j1 = (r - rem) / k;
                int sz = (int)prod[rem].size();
                int vm = (v % mod + mod) % mod;
                if (vm == 0)
                {
                    zero[rem][j0]++;
                    if (j1 + 1 < sz)
                    {
                        zero[rem][j1 + 1]--;
                    }
                }
                else
                {
                    prod[rem][j0] = (long long)prod[rem][j0] * vm % mod;
                    if (j1 + 1 < sz)
                    {
                        long long inv = qpow(vm, mod - 2);
                        prod[rem][j1 + 1] = (long long)prod[rem][j1 + 1] * inv % mod;
                    }
                }
            }
            for (int rem = 0; rem < k; rem++)
            {
                int l = (int)prod[rem].size() - 1;
                long long cur = 1;
                int cnt = 0;
                for (int j = 0; j < l; j++)
                {
                    cnt += zero[rem][j];
                    cur = cur * prod[rem][j] % mod;
                    int idx = rem + j * k;
                    if (idx >= n)
                    {
                        break;
                    }
                    long long mult = cnt > 0 ? 0LL : cur;
                    nums[idx] = (long long)nums[idx] * mult % mod;
                }
            }
        }
        int ans = 0;
        for (int x : nums)
        {
            ans ^= x;
        }
        return ans;
    }
};
