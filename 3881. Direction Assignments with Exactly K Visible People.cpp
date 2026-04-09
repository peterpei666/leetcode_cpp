#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    const int MOD = 1e9 + 7;
    
    int qpow(int base, int exp, int mod)
    {
        long long ans = 1;
        long long cur = base;
        while (exp)
        {
            if (exp & 1)
            {
                ans = (ans * cur) % mod;
            }
            cur = (cur * cur) % mod;
            exp >>= 1;
        }
        return ans % mod;
    }
    
    int C(int n, int k)
    {
        if (k < 0 || k > n)
        {
            return 0;
        }
        if (k == 0 || k == n)
        {
            return 1;
        }
        if (k > n / 2)
        {
            k = n - k;
        }
        int a = 1, b = 1;
        for (int i = 0; i < k; i++)
        {
            a = (1LL * a * (n - i)) % MOD;
            b = (1LL * b * (i + 1)) % MOD;
        }
        return (1LL * a * qpow(b, MOD - 2, MOD)) % MOD;
    }
    
public:
    int countVisiblePeople(int n, int pos, int k)
    {
        return (C(n - 1, k) * 2) % MOD;
    }
};
