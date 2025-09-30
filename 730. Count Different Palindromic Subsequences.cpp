#include <iostream>
#include <algorithm>
#include <stack>
#include <map>
using namespace std;

class Solution
{
public:
    int countPalindromicSubsequences(const string& s)
    {
        const int mod = 1e9 + 7;
        int n = (int)s.size();
        int dp[1000][1000] = {0};
        for (int i = 0; i < n; i++)
        {
            dp[i][i] = 1;
        }
        for (int l = 2; l <= n; l++)
        {
            for (int i = 0; i <= n - l; i++)
            {
                int j = i + l - 1;
                if (s[i] != s[j])
                {
                    dp[i][j] = ((dp[i + 1][j] + dp[i][j - 1]) % mod - dp[i + 1][j - 1] + mod) % mod;
                }
                else
                {
                    int low = i + 1, high = j - 1;
                    while (low <= high && s[low] != s[i])
                    {
                        low++;
                    }
                    while (high >= low && s[high] != s[j])
                    {
                        high--;
                    }
                    if (low > high)
                    {
                        dp[i][j] = (dp[i + 1][j - 1] * 2 + 2) % mod;
                    }
                    else if (low == high)
                    {
                        dp[i][j] = (dp[i + 1][j - 1] * 2 + 1) % mod;
                    }
                    else
                    {
                        dp[i][j] = ((dp[i + 1][j - 1] * 2 - dp[low + 1][high - 1])% mod + mod) % mod;
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
