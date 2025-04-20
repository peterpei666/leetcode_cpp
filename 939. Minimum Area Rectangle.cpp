#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minAreaRect(vector<vector<int>>& points)
    {
        unordered_map<int, unordered_set<int>> mp;
        for(auto p:points)
        {
            mp[p[0]].insert(p[1]);
        }
        int sz=(int)points.size(),area=INT_MAX;
        for(int i=0;i<sz;i++)
        {
            for(int j=i+1;j<sz;j++)
            {
                if(points[i][0]!=points[j][0]&&points[i][1]!=points[j][1])
                {
                    if(mp[points[i][0]].find(points[j][1])!=mp[points[i][0]].end()&&mp[points[j][0]].find(points[i][1])!=mp[points[j][0]].end())
                    {
                        area=min(area,abs(points[i][0]-points[j][0])*abs(points[i][1]-points[j][1]));
                    }
                }
            }
        }
        if(area==INT_MAX)
        {
            return 0;
        }
        return area;
    }
};
