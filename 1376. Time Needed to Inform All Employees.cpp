#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime)
    {
        vector<vector<int>> graph(n);
        for(int i=0;i<n;i++)
        {
            if(i!=headID)
            {
                graph[manager[i]].push_back(i);
            }
        }
        int time[n];
        memset(time,-1,sizeof(time));
        time[headID]=0;
        queue<int> q;
        q.push(headID);
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            for(int i:graph[cur])
            {
                if(time[i]==-1||time[i]>time[cur]+informTime[cur])
                {
                    time[i]=time[cur]+informTime[cur];
                    if(informTime[cur]!=0)
                    {
                        q.push(i);
                    }
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,time[i]);
        }
        return ans;
    }
};
