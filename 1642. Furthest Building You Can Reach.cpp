#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders)
    {
        priority_queue<int,vector<int>,greater<int>> pq;
        int i;
        int n=(int)heights.size();
        for(i=1;i<n;i++)
        {
            int dif=heights[i]-heights[i-1];
            if(dif<=0)
            {
                continue;
            }
            pq.push(dif);
            if(pq.size()>ladders)
            {
                bricks-=pq.top();
                pq.pop();
                if(bricks<0)
                {
                    return i-1;
                }
            }
        }
        return n-1;
    }
};
