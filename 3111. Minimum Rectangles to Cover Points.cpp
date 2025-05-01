#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

class Solution
{
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w)
    {
        vector<int> ps(points.size());
        int sz=(int)points.size();
        for(int i=0;i<sz;i++)
        {
            ps[i]=points[i][0];
        }
        sort(ps.begin(),ps.end());
        int cur=ps[0];
        int res=1;
        for(int p:ps)
        {
            if(p>cur+w)
            {
                res++;
                cur=p;
            }
        }
        return res;
    }
};
