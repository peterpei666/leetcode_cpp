#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minCost(vector<vector<int>>& grid)
    {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        bool mp[2][n][1024];
        memset(mp[0], 0, sizeof(mp[0]));
        mp[0][0][grid[0][0]] = true;
        for (int j = 1; j < n; j++)
        {
            for (int k = 0; k < 1024; k++)
            {
                if (mp[0][j - 1][k])
                {
                    mp[0][j][k ^ grid[0][j]] = true;
                }
            }
        }
        for (int i = 1; i < m; i++)
        {
            int t = i & 1;
            int p = t ^ 1;
            memset(mp[t], 0, sizeof(mp[t]));
            for (int k = 0; k < 1024; k++)
            {
                if (mp[p][0][k])
                {
                    mp[t][0][k ^ grid[i][0]] = true;
                }
            }
            for (int j = 1; j < n; j++)
            {
                for (int k = 0; k < 1024; k++)
                {
                    if (mp[t][j - 1][k] || mp[p][j][k])
                    {
                        mp[t][j][k ^ grid[i][j]] = true;
                    }
                }
            }
        }
        int t = (m - 1) & 1;
        for (int k = 0; k < 1024; k++)
        {
            if (mp[t][n - 1][k])
            {
                return k;
            }
        }
        return -1;
    }
};
