#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph(n);
        for (auto& pre : prerequisites)
        {
            graph[pre[1]].push_back(pre[0]);
        }
        bitset<2000> visited;
        bitset<2000> path;
        
        function<bool(int)> dfs = [&](int node) -> bool
        {
            if (visited.test(node))
            {
                return true;
            }
            if (path.test(node))
            {
                return false;
            }
            path.set(node);
            for (int next : graph[node])
            {
                if (!dfs(next))
                {
                    return false;
                }
            }
            visited.set(node);
            path.reset(node);
            return true;
        };
        
        for (int i = 0; i < n; i++)
        {
            if (!dfs(i))
            {
                return false;
            }
        }
        return true;
    }
};
