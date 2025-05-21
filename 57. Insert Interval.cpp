#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval)
    {
        int i=0;
        int n=(int)intervals.size();
        vector<vector<int>> ret;
        while(i<n&&intervals[i][1]<newInterval[0])
        {
            ret.push_back(intervals[i]);
            i++;
        }
        while(i<n&&intervals[i][0]<=newInterval[1])
        {
            newInterval[0]=min(newInterval[0],intervals[i][0]);
            newInterval[1]=max(newInterval[1],intervals[i][1]);
            i++;
        }
        ret.push_back(newInterval);
        while(i<n)
        {
            ret.push_back(intervals[i]);
            i++;
        }
        return ret;
    }
};
