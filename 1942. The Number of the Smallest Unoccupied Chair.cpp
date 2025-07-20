#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend)
    {
        int n=(int)times.size();
        vector<pair<int,int>> event(2*n);
        for(int i=0;i<n;i++)
        {
            event[2*i]={times[i][0],i};
            event[2*i+1]={times[i][1],-i-1};
        }
        sort(event.begin(),event.end());
        priority_queue<int,vector<int>,greater<int>> chair;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(int i=0;i<n;i++)
        {
            chair.push(i);
        }
        for(auto& [t,id]:event)
        {
            while(!pq.empty()&&pq.top().first<=t)
            {
                chair.push(pq.top().second);
                pq.pop();
            }
            if(id>=0)
            {
                if(id==targetFriend)
                {
                    return chair.top();
                }
                pq.push({times[id][1],chair.top()});
                chair.pop();
            }
        }
        return -1;
    }
};
