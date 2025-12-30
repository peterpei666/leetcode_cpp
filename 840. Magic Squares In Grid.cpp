#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
private:
    bool isMagic(vector<vector<int>>& grid, int x, int y)
    {
        bitset<9> mp;
        for (int i = -1; i < 2; i++)
        {
            for (int j = -1; j < 2; j++)
            {
                if (grid[x + i][y + j] > 9 || grid[x + i][y + j] == 0 || mp.test(grid[x + i][y + j] - 1))
                {
                    return false;
                }
                else
                {
                    mp.set(grid[x + i][y + j] - 1);
                }
            }
        }
        int t = grid[x - 1][y - 1] + grid[x][y] + grid[x + 1][y + 1];
        if (grid[x - 1][y + 1] + grid[x][y] + grid[x + 1][y - 1] != t)
        {
            return false;
        }
        for (int i = -1; i < 2; i++)
        {
            if (grid[x + i][y - 1] + grid[x + i][y] + grid[x + i][y + 1] != t || grid[x - 1][y + i] + grid[x][y + i] + grid[x + 1][y + i] != t)
            {
                return false;
            }
        }
        return true;
    }
    
public:
    int numMagicSquaresInside(vector<vector<int>>& grid)
    {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int ans = 0;
        for (int i = 1; i < m - 1; i++)
        {
            for (int j = 1; j < n - 1; j++)
            {
                if (isMagic(grid, i, j))
                {
                    ans++;
                }
            }
        }
        return ans;
    }
};
