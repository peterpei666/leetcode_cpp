#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals)
    {
        sort(intervals.begin(), intervals.end(), [&](const vector<int>& a, const vector<int>& b) { return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1]; });
        int n = (int)intervals.size();
        int sz = 0;
        int list[6000];
        for (int i = 0; i < n; i++)
        {
            int cnt = 0;
            for (int j = 0; j < sz && cnt < 2; j++)
            {
                if (list[j] <= intervals[i][1] && list[j] >= intervals[i][0])
                {
                    cnt++;
                }
            }
            for (int j = intervals[i][1]; cnt < 2; j--)
            {
                list[sz] = j;
                sz++;
                cnt++;
            }
        }
        return sz;
    }
};
