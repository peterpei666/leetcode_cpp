#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int minScore(int n, vector<vector<int>>& roads)
    {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto& r:roads)
        {
            graph[r[0]].push_back({r[1],r[2]});
            graph[r[1]].push_back({r[0],r[2]});
        }
        bitset<100001> visited;
        int res=INT_MAX;
        
        function<void(int)> dfs=[&](int node)
        {
            visited.set(node);
            for(auto& [next,dis]:graph[node])
            {
                res=min(res,dis);
                if(visited.test(next)==false)
                {
                    dfs(next);
                }
            }
        };
        
        dfs(1);
        return res;
    }
};
