#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k)
    {
        vector<vector<int>> mp(n);
        for (auto& e : edges)
        {
            mp[e[0]].push_back(e[1]);
            mp[e[1]].push_back(e[0]);
        }
        int ans = 0;
        
        function<int(int, int)> dfs = [&](int node, int parent) -> int
        {
            int sum = values[node] % k;
            bool valid = false;
            for (int next : mp[node])
            {
                if (next == parent)
                {
                    continue;
                }
                sum = (sum + dfs(next, node)) % k;
                valid = true;
            }
            if ((sum == 0 && valid) || (values[node] % k == 0 && valid == false))
            {
                ans++;
            }
            return sum;
        };
        
        dfs(0, -1);
        return ans;
    }
};
