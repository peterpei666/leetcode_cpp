#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int swimInWater(vector<vector<int>>& grid)
    {
        int memo[50][50];
        memset(memo, 0x7f, sizeof(memo));
        memo[0][0] = grid[0][0];
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
        pq.push({grid[0][0], {0, 0}});
        int n = (int)grid.size();
        int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
        while (!pq.empty())
        {
            auto [h, p] = pq.top();
            pq.pop();
            auto [x, y] = p;
            if (x == n - 1 && y == n - 1)
            {
                break;
            }
            for (int d = 0; d < 4; d++)
            {
                int nx = x + dir[d][0];
                int ny = y + dir[d][1];
                if (nx >= 0 && nx < n && ny >= 0 && ny < n)
                {
                    int temp = max(h, grid[nx][ny]);
                    if (temp < memo[nx][ny])
                    {
                        memo[nx][ny] = temp;
                        pq.push({temp, {nx, ny}});
                    }
                }
            }
        }
        return memo[n - 1][n - 1];
    }
};
