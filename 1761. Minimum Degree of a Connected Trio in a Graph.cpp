#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int minTrioDegree(int n, vector<vector<int>>& edges)
    {
        vector<bitset<400>> adj(n);
        int degree[400]={0};
        for(auto e:edges)
        {
            int u=e[0]-1,v=e[1]-1;
            if(u>v)
            {
                swap(u,v);
            }
            adj[u].set(v);
            degree[u]++;
            degree[v]++;
        }
        int res=INT_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(!adj[i].test(j))
                {
                    continue;
                }
                for(int k=j+1;k<n;k++)
                {
                    if(adj[i].test(k)&&adj[j].test(k))
                    {
                        res=min(res,degree[i]+degree[j]+degree[k]-6);
                    }
                }
            }
        }
        return res==INT_MAX?-1:res;
    }
};
