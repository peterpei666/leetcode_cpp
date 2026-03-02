#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k)
    {
        unordered_map<int, double> mp;
        int n = (int)points.size();
        for (int i = 0; i < n; i++)
        {
            mp[i] = sqrt(points[i][0] * points[i][0] + points[i][1] * points[i][1]);
        }
        priority_queue<pair<double, int>> pq;
        for (auto& [x, n] : mp)
        {
            pq.push(make_pair(n, x));
            if (pq.size() > k)
            {
                pq.pop();
            }
        }
        vector<vector<int>> ans(k);
        for (int i = 0; i < k; i++)
        {
            ans[i] = points[pq.top().second];
            pq.pop();
        }
        return ans;
    }
};
