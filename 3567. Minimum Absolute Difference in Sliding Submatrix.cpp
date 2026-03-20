#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k)
    {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        vector<vector<int>> ans(m - k + 1, vector<int>(n - k + 1));
        for (int i = 0; i < m - k + 1; i++)
        {
            for (int j = 0; j < n - k + 1; j++)
            {
                int temp[k * k];
                int sz = 0;
                for (int x = i; x < i + k; x++)
                {
                    for (int y = j; y < j + k; y++)
                    {
                        temp[sz++] = grid[x][y];
                    }
                }
                sort(&temp[0], &temp[0] + k * k);
                int t = temp[k * k - 1] - temp[0];
                for (sz = 1; sz < k * k && t; sz++)
                {
                    t = min(t, temp[sz] == temp[sz - 1] ? INT_MAX : temp[sz] - temp[sz - 1]);
                }
                ans[i][j] = t;
            }
        }
        return ans;
    }
};
