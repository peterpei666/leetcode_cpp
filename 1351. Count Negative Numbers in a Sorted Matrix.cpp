#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countNegatives(vector<vector<int>>& grid)
    {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int ans = 0;
        for (int i = m - 1; i >= 0 && grid[i][n - 1] < 0; i--)
        {
            for (int j = n - 1; j >= 0 && grid[i][j] < 0; j--)
            {
                ans++;
            }
        }
        return ans;
    }
};
