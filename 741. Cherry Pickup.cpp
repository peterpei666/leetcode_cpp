#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int cherryPickup(vector<vector<int>>& grid)
    {
        int memo[50][50][50];
        memset(memo, -1, sizeof(memo));
        int n = (int)grid.size();
        return max(0, dfs(0, 0, 0, n, memo, grid));
    }
    
    int dfs(int r1, int c1, int c2, int n, int memo[50][50][50], vector<vector<int>>& grid)
    {
        int r2 = r1 + c1 - c2;
        if (n == r1 || n == r2 || n == c1 || n == c2 || grid[r1][c1] == -1 || grid[r2][c2] == -1)
        {
            return INT_MIN;
        }
        else if (r1 == n - 1 && c1 == n - 1)
        {
            return grid[r1][c1];
        }
        else if (memo[r1][c1][c2] != -1)
        {
            return memo[r1][c1][c2];
        }
        else
        {
            int ans = grid[r1][c1];
            if (c1 != c2)
            {
                ans += grid[r2][c2];
            }
            ans += max(max(dfs(r1, c1 + 1, c2 + 1, n, memo, grid), dfs(r1 + 1, c1, c2 + 1, n, memo, grid)), max(dfs(r1, c1 + 1, c2, n, memo, grid), dfs(r1 + 1, c1, c2, n, memo, grid)));
            memo[r1][c1][c2] = ans;
            return ans;
        }
    }
};
