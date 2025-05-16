#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int find(vector<int>& parent,int x)
    {
        if(parent[x]<0)
        {
            return x;
        }
        parent[x]=find(parent,parent[x]);
        return parent[x];
    }
    
    bool unite(vector<int>& parent,int x,int y)
    {
        int p1=find(parent,x);
        int p2=find(parent,y);
        if(p1==p2)
        {
            return false;
        }
        if(parent[p1]<parent[p2])
        {
            parent[p1]+=parent[p2];
            parent[p2]=p1;
        }
        else
        {
            parent[p2]+=parent[p1];
            parent[p1]=p2;
        }
        return true;
    }
    
    vector<int> findRedundantConnection(vector<vector<int>>& edges)
    {
        int n=(int)edges.size();
        vector<int> parent(n+1,-1);
        for(int i=0;i<n;i++)
        {
            if(!unite(parent,edges[i][0],edges[i][1]))
            {
                return edges[i];
            }
        }
        return edges[0];
    }
};
