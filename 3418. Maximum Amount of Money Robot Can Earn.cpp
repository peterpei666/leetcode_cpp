#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumAmount(vector<vector<int>>& coins)
    {
        int m = (int)coins.size();
        int n = (int)coins[0].size();
        int dp[2][500][3];
        memset(dp, 0x80, sizeof(dp));
        dp[0][0][1] = dp[0][0][2] = 0;
        dp[0][0][0] = coins[0][0];
        for (int i = 0; i < m; i++)
        {
            if (i)
            {
                memset(dp[i & 1], 0x80, sizeof(dp) / 2);
            }
            for (int j = 0; j < n; j++)
            {
                for (int k = 0; k < 3; k++)
                {
                    if (i)
                    {
                        dp[i & 1][j][k] = max(dp[i & 1][j][k], dp[(i - 1) & 1][j][k] + coins[i][j]);
                    }
                    if (i && k)
                    {
                        dp[i & 1][j][k] = max(dp[i & 1][j][k], dp[(i - 1) & 1][j][k - 1]);
                    }
                    if (j)
                    {
                        dp[i & 1][j][k] = max(dp[i & 1][j][k], dp[i & 1][j - 1][k] + coins[i][j]);
                    }
                    if (j && k)
                    {
                        dp[i & 1][j][k] = max(dp[i & 1][j][k], dp[i & 1][j - 1][k - 1]);
                    }
                }
            }
        }
        int ans = max(dp[(m - 1) & 1][n - 1][0], max(dp[(m - 1) & 1][n - 1][1], dp[(m - 1) & 1][n - 1][2]));
        return ans;
    }
};
