#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numberOfPaths(vector<vector<int>>& grid, int k)
    {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        const int mod = 1e9 + 7;
        int dp[n][k];
        memset(dp, 0, sizeof(dp));
        dp[0][grid[0][0] % k] = 1;
        for (int j = 1; j < n; j++)
        {
            memcpy(&dp[j][grid[0][j] % k], &dp[j - 1][0], sizeof(int) * (k - grid[0][j] % k));
            memcpy(&dp[j][0], &dp[j - 1][k - grid[0][j] % k], sizeof(int) * (grid[0][j] % k));
        }
        for (int i = 1; i < m; i++)
        {
            int new_dp[n][k];
            memset(new_dp, 0, k * n * sizeof(int));
            memcpy(&new_dp[0][grid[i][0] % k], &dp[0][0], sizeof(int) * (k - grid[i][0] % k));
            memcpy(&new_dp[0][0], &dp[0][k - grid[i][0] % k], sizeof(int) * (grid[i][0] % k));
            for (int j = 1; j < n; j++)
            {
                memcpy(&new_dp[j][grid[i][j] % k], &dp[j][0], sizeof(int) * (k - grid[i][j] % k));
                memcpy(&new_dp[j][0], &dp[j][k - grid[i][j] % k], sizeof(int) * (grid[i][j] % k));
                for (int t = 0; t < k; t++)
                {
                    new_dp[j][(t + grid[i][j]) % k] = (new_dp[j][(t + grid[i][j]) % k] + new_dp[j - 1][t]) % mod;
                }
            }
            memcpy(dp, new_dp, sizeof(dp));
        }
        return dp[n - 1][0];
    }
};
