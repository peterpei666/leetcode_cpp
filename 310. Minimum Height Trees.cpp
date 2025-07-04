#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges)
    {
        if(n==1)
        {
            return {0};
        }
        vector<vector<int>> graph(n);
        vector<int> degree(n,0);
        for(auto& e:edges)
        {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }
        queue<int> q;
        for(int i=0;i<n;i++)
        {
            if(degree[i]==1)
            {
                q.push(i);
            }
        }
        int remain=n;
        while(remain>2)
        {
            int sz=(int)q.size();
            remain-=sz;
            while(sz)
            {
                sz--;
                int cur=q.front();
                q.pop();
                for(int next:graph[cur])
                {
                    degree[next]--;
                    if(degree[next]==1)
                    {
                        q.push(next);
                    }
                }
            }
        }
        vector<int> ret;
        while(!q.empty())
        {
            ret.push_back(q.front());
            q.pop();
        }
        return ret;
    }
};
