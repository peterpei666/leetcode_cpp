#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int maxEvents(vector<vector<int>>& events)
    {
        int n=(int)events.size();
        int m=0;
        for(auto& e:events)
        {
            m=max(m,e[1]);
        }
        sort(events.begin(),events.end());
        priority_queue<int,vector<int>,greater<>> pq;
        int ans=0;
        for(int i=0,j=0;i<=m;i++)
        {
            while(j<n&&events[j][0]<=i)
            {
                pq.push(events[j][1]);
                j++;
            }
            while(!pq.empty()&&pq.top()<i)
            {
                pq.pop();
            }
            if(!pq.empty())
            {
                pq.pop();
                ans++;
            }
        }
        return ans;
    }
};
