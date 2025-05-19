#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, int v, int mp, int md)
    {
        priority_queue<pair<int,int>> pq;
        if(v)
        {
            for(auto& r:restaurants)
            {
                if(r[2]==v&&r[3]<=mp&&r[4]<=md)
                {
                    pq.push({r[1],r[0]});
                }
            }
        }
        else
        {
            for(auto& r:restaurants)
            {
                if(r[3]<=mp&&r[4]<=md)
                {
                    pq.push({r[1],r[0]});
                }
            }
        }
        int n=(int)pq.size();
        vector<int> ret(n);
        for(int i=0;i<n;i++)
        {
            ret[i]=pq.top().second;
            pq.pop();
        }
        return ret;
    }
};
