#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
private:
    static inline int one(char c)
    {
        if (c == '*') return 9;
        if (c == '0') return 0;
        return 1;
    }
    
    int two(char c1, char c2)
    {
        if (c1 == '*')
        {
            if (c2 == '*') return 15;
            if (c2 <= '6') return 2;
            return 1;
        }
        if (c1 == '1')
        {
            if (c2 == '*') return 9;
            return 1;
        }
        if (c1 == '2')
        {
            if (c2 == '*') return 6;
            return c2 < '7' ? 1 : 0;
        }
        return 0;
    }
    
public:
    int numDecodings(const string& s)
    {
        const int mod = 1e9 + 7;
        int dp[3] = {0};
        int n = (int)s.size();
        dp[(n - 1) % 3] = one(s[n - 1]);
        if (n > 1)
        {
            dp[(n - 2) % 3] = one(s[n - 2]) * dp[(n - 1) % 3] + two(s[n - 2], s[n - 1]);
            for (int i = n - 3; i >= 0; i--)
            {
                dp[i % 3] = (1LL * one(s[i]) * dp[(i + 1) % 3] + 1LL * two(s[i], s[i + 1]) * dp[(i + 2) % 3]) % mod;
            }
        }
        return dp[0];
    }
};
