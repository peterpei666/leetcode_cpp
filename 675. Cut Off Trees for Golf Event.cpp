#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int cutOffTree(vector<vector<int>>& forest)
    {
        unordered_map<int, pair<int, int>> mp;
        priority_queue<int, vector<int>, greater<>> pq;
        int m = (int)forest.size();
        int n = (int)forest[0].size();
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (forest[i][j] > 1)
                {
                    pq.push(forest[i][j]);
                    mp[forest[i][j]] = {i, j};
                }
            }
        }
        const int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};
        
        function<int(int, int, int, int)> bfs = [&](int x1, int y1, int x2, int y2) -> int
        {
            bitset<50> visited[50];
            visited[x1].set(y1);
            queue<pair<int, pair<int, int>>> q;
            q.push({0, {x1, y1}});
            while (!q.empty())
            {
                auto [step, p] = q.front();
                auto [x, y] = p;
                q.pop();
                if (x == x2 && y == y2)
                {
                    return step;
                }
                for (int d = 0; d < 4; d++)
                {
                    int nx = x + dir[d][0];
                    int ny = y + dir[d][1];
                    if (nx >= 0 && nx < m && ny >= 0 && ny < n && !visited[nx].test(ny) && forest[nx][ny] > 0)
                    {
                        visited[nx].set(ny);
                        q.push({step + 1, {nx, ny}});
                    }
                }
            }
            return -1;
        };
        
        int ans = 0;
        int x = 0, y = 0;
        while (!pq.empty())
        {
            auto [nx, ny] = mp[pq.top()];
            pq.pop();
            int dist = bfs(x, y, nx, ny);
            if (dist == -1)
            {
                return -1;
            }
            ans += dist;
            x = nx;
            y = ny;
        }
        return ans;
    }
};
