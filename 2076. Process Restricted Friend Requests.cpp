#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int find(int parent[],int x)
    {
        if(parent[x]==x)
        {
            return x;
        }
        parent[x]=find(parent,parent[x]);
        return parent[x];
    }
    
    inline void unite(int parent[],int a,int b)
    {
        int p1=find(parent,a);
        int p2=find(parent,b);
        parent[max(p1,p2)]=min(p1,p2);
    }
    
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests)
    {
        int parent[n];
        int temp[n];
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        int q=(int)requests.size();
        vector<bool> ret(q);
        for(int i=0;i<q;i++)
        {
            memcpy(temp,parent,sizeof(parent));
            unite(temp,requests[i][0],requests[i][1]);
            bool f=true;
            for(auto& re:restrictions)
            {
                if(find(temp,re[0])==find(temp,re[1]))
                {
                    f=false;
                    break;
                }
            }
            ret[i]=f;
            if(f)
            {
                memcpy(parent,temp,sizeof(parent));
            }
        }
        return ret;
    }
};
