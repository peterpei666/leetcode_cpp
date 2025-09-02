#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numberOfPairs(vector<vector<int>>& points)
    {
        int n = (int)points.size();
        sort(points.begin(), points.end(), [&](const vector<int>& a, const vector<int>& b) { return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0]; });
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int y = INT_MIN;
            for (int j = i + 1; j < n; j++)
            {
                if (points[i][1] >= points[j][1] && y < points[j][1])
                {
                    cnt++;
                    y = points[j][1];
                }
            }
        }
        return cnt;
    }
};
