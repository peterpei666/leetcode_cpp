#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& prerequisites, vector<vector<int>>& queries)
    {
        vector<vector<int>> graph(n);
        for (auto& pre : prerequisites)
        {
            graph[pre[1]].push_back(pre[0]);
        }
        bitset<100> visited;
        
        function<bool(int, int)> dfs = [&](int node, int target) -> bool
        {
            if (node == target)
            {
                return true;
            }
            visited.set(node);
            for (int next : graph[node])
            {
                if (!visited.test(next))
                {
                    if (dfs(next, target))
                    {
                        return true;
                    }
                }
            }
            return false;
        };
        
        int q = (int)queries.size();
        vector<bool> ans(q);
        for (int i = 0; i < q; i++)
        {
            visited.reset();
            ans[i] = dfs(queries[i][1], queries[i][0]);
        }
        return ans;
    }
};
