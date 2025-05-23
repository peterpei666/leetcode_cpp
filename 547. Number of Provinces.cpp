#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int find(int x,int parent[])
    {
        if(x==parent[x])
        {
            return x;
        }
        else
        {
            parent[x]=find(parent[x],parent);
            return parent[x];
        }
    }
    
    void unite(int a,int b,int parent[])
    {
        int p1=find(a,parent);
        int p2=find(b,parent);
        if(p1>p2)
        {
            parent[p1]=p2;
        }
        else if(p1<p2)
        {
            parent[p2]=p1;
        }
    }
    
    int findCircleNum(vector<vector<int>>& isConnected)
    {
        int n=(int)isConnected.size();
        int parent[n];
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j])
                {
                    unite(i,j,parent);
                }
            }
        }
        bitset<200> found;
        for(int i=0;i<n;i++)
        {
            found.set(find(i,parent));
        }
        return (int)found.count();
    }
};
