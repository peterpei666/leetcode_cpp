#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int dfs(int node,int parent,vector<vector<int>>& graph,int k)
    {
        if(k<0)
        {
            return 0;
        }
        int ans=1;
        for(int next:graph[node])
        {
            if(parent==next)
            {
                continue;
            }
            ans+=dfs(next,node,graph,k-1);
        }
        return ans;
    }
    
    vector<int> build(vector<vector<int>>& edges,int k)
    {
        int n=(int)edges.size()+1;
        vector<vector<int>> graph(n);
        for(auto& e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        vector<int> list(n);
        for(int i=0;i<n;i++)
        {
            list[i]=dfs(i,-1,graph,k);
        }
        return list;
    }
    
    vector<int> maxTargetNodes(vector<vector<int>>& edges1,vector<vector<int>>& edges2,int k)
    {
        vector<int> tree1=build(edges1,k);
        vector<int> tree2=build(edges2,k-1);
        int m=0;
        for(int i:tree2)
        {
            m=max(i,m);
        }
        for(int& i:tree1)
        {
            i+=m;
        }
        return tree1;
    }
};
