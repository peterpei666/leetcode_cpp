#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites)
    {
        vector<vector<int>> graph(n);
        for (auto& pre : prerequisites)
        {
            graph[pre[1]].push_back(pre[0]);
        }
        bitset<2000> visited;
        bitset<2000> processing;
        vector<int> ans;
        
        function<bool(int)> dfs = [&](int node) -> bool
        {
            if (processing.test(node))
            {
                return false;
            }
            if (visited.test(node))
            {
                return true;
            }
            visited.set(node);
            processing.set(node);
            for (int next : graph[node])
            {
                if (!dfs(next))
                {
                    return false;
                }
            }
            processing.reset(node);
            ans.push_back(node);
            return true;
        };
        
        for (int i = 0; i < n; i++)
        {
            if (!dfs(i))
            {
                return {};
            }
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
