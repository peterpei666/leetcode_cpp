#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numberOfStableArrays(int zero, int one, int limit)
    {
        const int mod = 1e9 + 7;
        int dp[zero + 1][one + 1][2];
        memset(dp, 0, sizeof(dp));
        for (int i = 1, k = min(zero, limit) + 1; i < k; i++)
        {
            dp[i][0][0] = 1;
        }
        for (int i = 1, k = min(one, limit) + 1; i < k; i++)
        {
            dp[0][i][1] = 1;
        }
        for (int i = 1; i <= zero; i++)
        {
            for (int j = 1; j <= one; j++)
            {
                long long val0 = dp[i - 1][j][0] + dp[i - 1][j][1];
                if (i > limit)
                {
                    val0 -= dp[i - limit - 1][j][1];
                }
                dp[i][j][0] = (val0 + mod) % mod;
                long long val1 = dp[i][j - 1][0] + dp[i][j - 1][1];
                if (j > limit)
                {
                    val1 -= dp[i][j - limit - 1][0];
                }
                dp[i][j][1] = (val1 + mod) % mod;
            }
        }
        return (dp[zero][one][0] + dp[zero][one][1]) % mod;
    }
};
