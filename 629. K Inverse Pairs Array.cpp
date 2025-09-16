#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int kInversePairs(int n, int k)
    {
        int dp[2][k + 1];
        memset(dp, 0, sizeof(dp));
        dp[0][0] = 1;
        dp[1][0] = 1;
        const int mod = 1e9 + 7;
        for (int i = 1; i <= n; i++)
        {
            dp[i & 1][0] = dp[(i - 1) & 1][0];
            for (int j = 1; j < i && j <= k; j++)
            {
                dp[i & 1][j] = (dp[(i - 1) & 1][j] + dp[i & 1][j - 1]) % mod;
            }
            for (int j = i; j <= k; j++)
            {
                dp[i & 1][j] = (dp[(i - 1) & 1][j] + dp[i & 1][j - 1]) % mod;
                dp[i & 1][j] = (dp[i & 1][j] + mod - dp[(i - 1) & 1][j - i]) % mod;
            }
        }
        return dp[n & 1][k];
    }
};
