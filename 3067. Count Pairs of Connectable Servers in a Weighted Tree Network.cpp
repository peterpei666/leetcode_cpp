#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int dfs(int node,int parent,int s,int dis,vector<vector<pair<int,int>>>& list)
    {
        int total=0,next,weight;
        if(dis%s==0)
        {
            total++;
        }
        for(auto& p:list[node])
        {
            next=p.first;
            weight=p.second;
            if(next!=parent)
            {
                total+=dfs(next,node,s,dis+weight,list);
            }
            
        }
        return total;
    }
    
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed)
    {
        int m=(int)edges.size();
        int n=m+1;
        vector<vector<pair<int,int>>> list(n);
        for(auto& e:edges)
        {
            list[e[0]].push_back({e[1],e[2]});
            list[e[1]].push_back({e[0],e[2]});
        }
        vector<int> ret(n);
        for(int i=0;i<n;i++)
        {
            int count=0,res=0;
            for(auto [n,w]:list[i])
            {
                int temp=dfs(n,i,signalSpeed,w,list);
                res+=count*temp;
                count+=temp;
            }
            ret[i]=res;
        }
        return ret;
    }
};
