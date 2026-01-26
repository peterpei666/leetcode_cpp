#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    void bfs(vector<vector<int>>& graph, vector<int>& dis, int node)
    {
        queue<int> q;
        q.push(node);
        int t = 1;
        while (!q.empty())
        {
            int sz = (int)q.size();
            for (int i = 0; i < sz; i++)
            {
                int temp = q.front();
                q.pop();
                for (int next : graph[temp])
                {
                    if (dis[next] == -1)
                    {
                        dis[next] = t;
                        q.push(next);
                    }
                }
            }
            t++;
        }
    }
    
    bool valid(int a, int b, int c)
    {
        return 1LL * a * a + 1LL * b * b == 1LL * c * c || 1LL * b * b + 1LL * c * c == 1LL * a * a || 1LL * a * a + 1LL * c * c == 1LL * b * b;
    }
    
public:
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z)
    {
        vector<vector<int>> graph(n);
        for (auto& e : edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> dis1(n, -1);
        vector<int> dis2(n, -1);
        vector<int> dis3(n, -1);
        dis1[x] = 0;
        dis2[y] = 0;
        dis3[z] = 0;
        bfs(graph, dis1, x);
        bfs(graph, dis2, y);
        bfs(graph, dis3, z);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (valid(dis1[i], dis2[i], dis3[i]))
            {
                ans++;
            }
        }
        return ans;
    }
};
