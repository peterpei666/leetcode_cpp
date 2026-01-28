#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct Node
{
    int cost;
    int t, x, y;
    
    bool operator>(const Node& other) const
    {
        return cost > other.cost;
    }
};

class Solution
{
public:
    int minCost(vector<vector<int>>& grid, int k)
    {
        int m = (int)grid.size();
        int n = (int)grid[0].size();
        int dis[k + 1][80][80];
        memset(dis, 0x7f, sizeof(dis));
        vector<tuple<int, int, int>> cells;
        cells.reserve(m * n);
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cells.emplace_back(grid[i][j], i, j);
            }
        }
        sort(cells.begin(), cells.end());
        vector<int> ptr(k + 1, 0);
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        dis[0][0][0] = 0;
        pq.push({0, 0, 0, 0});
        while (!pq.empty())
        {
            auto [cost, t, x, y] = pq.top();
            pq.pop();
            if (cost != dis[t][x][y])
            {
                continue;
            }
            if (x + 1 < m)
            {
                int nc = cost + grid[x + 1][y];
                if (nc < dis[t][x + 1][y])
                {
                    dis[t][x + 1][y] = nc;
                    pq.push({nc, t, x + 1, y});
                }
            }
            if (y + 1 < n)
            {
                int nc = cost + grid[x][y + 1];
                if (nc < dis[t][x][y + 1])
                {
                    dis[t][x][y + 1] = nc;
                    pq.push({nc, t, x, y + 1});
                }
            }
            if (t < k)
            {
                int &p = ptr[t];
                while (p < (int)cells.size())
                {
                    auto [v, nx, ny] = cells[p];
                    if (v > grid[x][y])
                    {
                        break;
                    }
                    if (cost < dis[t + 1][nx][ny])
                    {
                        dis[t + 1][nx][ny] = cost;
                        pq.push({cost, t + 1, nx, ny});
                    }
                    p++;
                }
            }
        }
        int ans = 0x7f7f7f7f;
        for (int t = 0; t <= k; t++)
        {
            ans = min(ans, dis[t][m - 1][n - 1]);
        }
        return ans;
    }
};
