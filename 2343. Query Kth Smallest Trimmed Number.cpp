#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries)
    {
        int memo[101][101];
        int m = (int)nums[0].size();
        int n = (int)nums.size();
        vector<pair<string, int>> mp;
        for (int i = 0; i < n; i++)
        {
            mp.push_back(make_pair(nums[i], i));
        }
        for (int i = 1; i <= m; i++)
        {
            stable_sort(mp.begin(), mp.end(), [&](const pair<string, int>& a, const pair<string, int>& b) { return a.first[m - i] < b.first[m - i]; });
            for (int j = 0; j < n; j++)
            {
                memo[i][j] = mp[j].second;
            }
        }
        vector<int> ans;
        for (auto& q : queries)
        {
            ans.push_back(memo[q[1]][q[0] - 1]);
        }
        return ans;
    }
};
