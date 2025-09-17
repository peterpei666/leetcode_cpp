#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countStableSubsequences(vector<int>& nums)
    {
        const int mod = 1e9 + 7;
        long long dp[2][2] = {0};
        for (int i : nums)
        {
            if (i & 1)
            {
                dp[0][1] = (dp[0][1] + dp[0][0]) % mod;
                dp[0][0] = (dp[0][0] + dp[1][0] + dp[1][1] + 1) % mod;
            }
            else
            {
                dp[1][1] = (dp[1][1] + dp[1][0]) % mod;
                dp[1][0] = (dp[1][0] + dp[0][0] + dp[0][1] + 1) % mod;
            }
        }
        return (dp[0][0] + dp[0][1] + dp[1][0] + dp[1][1]) % mod;
    }
};
