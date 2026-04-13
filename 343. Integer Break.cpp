#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int integerBreak(int n)
    {
        int dp[60];
        dp[1] = 1;
        dp[2] = 1;
        for (int i = 3; i <= n; i++)
        {
            int t = 1;
            for (int j = 1; j < i; j++)
            {
                t = max(t, max(j, dp[j]) * max(i - j, dp[i - j]));
            }
            dp[i] = t;
        }
        return dp[n];
    }
};
