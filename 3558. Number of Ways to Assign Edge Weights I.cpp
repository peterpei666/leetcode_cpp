#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int ans;
    const int mod=1e9+7;
    
    void dfs(int node,int parent,vector<vector<int>>& graph,int cur)
    {
        ans=max(ans,cur);
        for(int next:graph[node])
        {
            if(next!=parent)
            {
                dfs(next,node,graph,cur+1);
            }
        }
    }
    
    int powmod(int x)
    {
        long long temp=2;
        long long ans=1;
        while(x)
        {
            if(x&1)
            {
                ans*=temp;
                ans%=mod;
            }
            x>>=1;
            temp=temp*temp;
            temp%=mod;
        }
        return ans%mod;
    }
    
public:
    int assignEdgeWeights(vector<vector<int>>& edges)
    {
        int n=(int)edges.size();
        vector<vector<int>> graph(n+2);
        for(auto& e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        ans=0;
        dfs(1,-1,graph,0);
        return powmod(ans-1);
    }
};
