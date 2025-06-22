#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost)
    {
        vector<vector<int>> graph(n);
        for(auto& e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        
        function<pair<long long,int>(int,int)> dfs=[&](int node,int p) -> pair<long long,int>
        {
            if(graph[node].size()==1&&node)
            {
                return {cost[node],0};
            }
            int cnt=0;
            long long m=0;
            vector<long long> temp;
            for(int c:graph[node])
            {
                if(c!=p)
                {
                    auto t=dfs(c,node);
                    temp.push_back(t.first);
                    cnt+=t.second;
                    m=max(m,t.first);
                }
            }
            for(long long c:temp)
            {
                if(c<m)
                {
                    cnt++;
                }
            }
            return {cost[node]+m,cnt};
        };
        
        return dfs(0,-1).second;
    }
};
