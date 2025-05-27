#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges)
    {
        const int mod=1e9+7;
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto& e:edges)
        {
            graph[e[0]].push_back({e[1],e[2]});
            graph[e[1]].push_back({e[0],e[2]});
        }
        vector<int> dis(n+1,INT_MAX);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        dis[n]=0;
        pq.push({0,n});
        while(!pq.empty())
        {
            auto [d,x]=pq.top();
            pq.pop();
            if(d>dis[x])
            {
                continue;
            }
            for(auto& [nx,nd]:graph[x])
            {
                if(d+nd<dis[nx])
                {
                    dis[nx]=d+nd;
                    pq.push({d+nd,nx});
                }
            }
        }
        vector<int> dp(n+1,-1);
        
        function<int(int)> dfs=[&](int node)->int
        {
            if(node==n)
            {
                return 1;
            }
            if(dp[node]!=-1)
            {
                return dp[node];
            }
            int ans=0;
            for(auto& [nx,_]:graph[node])
            {
                if(dis[nx]<dis[node])
                {
                    ans+=dfs(nx);
                    ans%=mod;
                }
            }
            dp[node]=ans;
            return ans;
        };
        
        return dfs(1);
    }
};
