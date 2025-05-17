#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <numeric>
using namespace std;

class Solution
{
public:
    int find(int parent[],int x)
    {
        if(parent[x]==x)
        {
            return x;
        }
        parent[x]=find(parent,parent[x]);
        return parent[x];
    }
    
    void unite(int parent[],int x,int y)
    {
        int p1=find(parent,x);
        int p2=find(parent,y);
        if(p1<p2)
        {
            parent[p2]=p1;
        }
        else if(p1>p2)
        {
            parent[p1]=p2;
        }
    }
    
    long long countPairs(int n, vector<vector<int>>& edges)
    {
        int parent[n];
        iota(&parent[0],&parent[0]+n,0);
        for(auto& e:edges)
        {
            unite(parent,e[0],e[1]);
        }
        unordered_map<int,int> list;
        for(int i=0;i<n;i++)
        {
            list[find(parent,i)]++;
        }
        long long ret=0;
        for(auto [_,m]:list)
        {
            ret+=(long long)m*(long long)(n-m);
        }
        return ret/2;
    }
};
