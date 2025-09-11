#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int checkRecord(int n)
    {
        const int mod = 1e9 + 7;
        int dp[2][2][3];
        memset(dp, 0, sizeof(dp));
        dp[0][0][0] = 1;
        dp[0][0][1] = 1;
        dp[0][1][0] = 1;
        for (int i = 1; i < n; i++)
        {
            dp[i % 2][0][0] = ((long long)dp[(i - 1) % 2][0][0] + dp[(i - 1) % 2][0][1] % mod + dp[(i - 1) % 2][0][2]) % mod;
            dp[i % 2][0][1] = dp[(i - 1) % 2][0][0];
            dp[i % 2][0][2] = dp[(i - 1) % 2][0][1];
            dp[i % 2][1][0] = ((long long)dp[(i - 1) % 2][0][0] + dp[(i - 1) % 2][0][1] + dp[(i - 1) % 2][0][2] + dp[(i - 1) % 2][1][0] + dp[(i - 1) % 2][1][1] + dp[(i - 1) % 2][1][2]) % mod;
            dp[i % 2][1][1] = dp[(i - 1) % 2][1][0];
            dp[i % 2][1][2] = dp[(i - 1) % 2][1][1];
        }
        int ans = 0;
        for (int i = 0; i < 3; i++)
        {
            ans = (ans + dp[(n - 1) % 2][0][i]) % mod;
            ans = (ans + dp[(n - 1) % 2][1][i]) % mod;
        }
        return ans;
    }
};
