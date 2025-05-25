#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings)
    {
        vector<pair<int,int>> event;
        for(auto& b:buildings)
        {
            event.push_back({b[0],-b[2]});
            event.push_back({b[1],b[2]});
        }
        sort(event.begin(),event.end());
        map<int,int> height;
        vector<vector<int>> ret;
        height[0]=1;
        int prev=0;
        for(auto& [x,h]:event)
        {
            if(h<0)
            {
                height[-h]++;
            }
            else
            {
                height[h]--;
                if(height[h]==0)
                {
                    height.erase(h);
                }
            }
            int cur=height.rbegin()->first;
            if(cur!=prev)
            {
                ret.push_back({x,cur});
                prev=cur;
            }
        }
        return ret;
    }
};
