#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    const int mod = 1e9 + 7;
    
    int find(int m, int n, vector<vector<vector<int>>>& dp, int i, int j, int dir, vector<vector<int>>& grid)
    {
        if (i >= m || j >= n)
        {
            return 0;
        }
        if (i == m - 1 && j == n - 1)
        {
            return 1;
        }
        if (dp[i][j][dir] != -1)
        {
            return dp[i][j][dir];
        }
        if (grid[i][j] == 1)
        {
            if (dir == 1)
            {
                return find(m, n, dp, i + 1, j, 0, grid);
            }
            else if (dir == 0)
            {
                return find(m, n, dp, i, j + 1, 1, grid);
            }
        }
        long long move = 0;
        if (j + 1 < n)
        {
            move += find(m, n, dp, i, j + 1, 1, grid);
        }
        if (i + 1 < m)
        {
            move += find(m, n, dp, i + 1, j, 0, grid);
        }
        dp[i][j][dir] = move % mod;
        return dp[i][j][dir];
    }
    
public:
    int uniquePaths(vector<vector<int>>& grid)
    {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(2, -1)));
        return find(m, n, dp, 0, 0, 0, grid);
    }
};
