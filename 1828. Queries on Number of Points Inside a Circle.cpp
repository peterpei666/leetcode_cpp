#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries)
    {
        int n=(int)queries.size();
        int m=(int)points.size();
        vector<int> ret(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if((queries[i][0]-points[j][0])*(queries[i][0]-points[j][0])+(queries[i][1]-points[j][1])*(queries[i][1]-points[j][1])<=queries[i][2]*queries[i][2])
                {
                    ret[i]++;
                }
            }
        }
        return ret;
    }
};
