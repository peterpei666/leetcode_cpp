#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <numeric>
using namespace std;

class Solution
{
public:
    int find(int n,int parent[n],int x)
    {
        if(parent[x]==x)
        {
            return x;
        }
        parent[x]=find(n,parent,parent[x]);
        return parent[x];
    }
    
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps)
    {
        int n=(int)source.size();
        int parent[n];
        iota(&parent[0],&parent[0]+n,0);
        for(auto& swap:allowedSwaps)
        {
            int p1=find(n,parent,swap[0]);
            int p2=find(n,parent,swap[1]);
            if(p1<p2)
            {
                parent[p2]=p1;
            }
            else if(p1>p2)
            {
                parent[p1]=p2;
            }
        }
        unordered_map<int,vector<int>> groups;
        for(int i=0;i<n;i++)
        {
            groups[find(n,parent,i)].push_back(i);
        }
        int dis=0;
        for(auto& [_,group]:groups)
        {
            unordered_map<int,int> count;
            for(int i:group)
            {
                count[source[i]]++;
            }
            for(int i:group)
            {
                if(count[target[i]])
                {
                    count[target[i]]--;
                }
                else
                {
                    dis++;
                }
            }
        }
        return dis;
    }
};
