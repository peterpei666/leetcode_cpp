#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int memo[50002];

    int nCr_mod2(int n, int r)
    {
        return ((r & ~n) == 0);
    }

    int nCr_mod5(int n, int r)
    {
        static const int p = 5;
        static const int fact[5] = {1, 1, 2, 1, 4};
        static const int invfact[5] = {1, 1, 3, 1, 4};
        int res = 1;
        while (n > 0 || r > 0)
        {
            int ni = n % p;
            int ri = r % p;
            if (ri > ni) return 0;
            int val = fact[ni] * invfact[ri] % p * invfact[ni - ri] % p;
            res = res * val % p;
            n /= p;
            r /= p;
        }
        return res;
    }

    int nCr_mod10(int n, int r)
    {
        int a2 = nCr_mod2(n, r);
        int a5 = nCr_mod5(n, r);
        for (int x = 0; x < 10; x++)
        {
            if (x % 2 == a2 && x % 5 == a5)
            {
                return x;
            }
        }
        return 0;
    }
    
public:
    bool hasSameDigits(const string& s)
    {
        int n = (int)s.size();
        if (n <= 1)
        {
            return true;
        }
        int m = n - 2;
        memo[0] = 1;
        for (int i = 1; i <= m / 2 + 1; i++)
        {
            memo[i] = nCr_mod10(m, i);
        }
        int temp1 = 0, temp2 = 0;
        for (int i = 0; i < n - 1; i++)
        {
            temp1 = (temp1 + (s[i] - '0') * memo[min(i, m - i)]) % 10;
            temp2 = (temp2 + (s[i + 1] - '0') * memo[min(i, m - i)]) % 10;
        }
        return temp1 == temp2;
    }
};
