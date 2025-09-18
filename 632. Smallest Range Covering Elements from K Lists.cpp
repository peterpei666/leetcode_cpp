#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

class Solution
{
public:
    vector<int> smallestRange(vector<vector<int>>& nums)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        int n = (int)nums.size();
        int sz[n];
        int col[n];
        int r = INT_MIN;
        for (int i = 0; i < n; i++)
        {
            col[i] = 1;
            sz[i] = (int)nums[i].size();
            pq.push({nums[i][0], i});
            r = max(r, nums[i][0]);
        }
        int ans_l = 0, ans_r = 0;
        int dif = INT_MAX;
        while (pq.size() == n)
        {
            auto [l, row] = pq.top();
            if (r - l < dif)
            {
                dif = r - l;
                ans_l = l;
                ans_r = r;
            }
            pq.pop();
            if (col[row] < sz[row])
            {
                r = max(r, nums[row][col[row]]);
                pq.push({nums[row][col[row]], row});
                col[row]++;
            }
        }
        return {ans_l, ans_r};
    }
};
