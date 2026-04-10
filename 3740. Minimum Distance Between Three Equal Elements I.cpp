#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int minimumDistance(vector<int>& nums)
    {
        unordered_map<int, vector<int>> mp;
        int n = (int)nums.size();
        for (int i = 0; i < n; i++)
        {
            mp[nums[i]].push_back(i);
        }
        int ans = INT_MAX;
        for (auto& [_, pos] : mp)
        {
            int m = (int)pos.size();
            for (int i = 2; i < m; i++)
            {
                ans = min(ans, 2 * (pos[i] - pos[i - 2]));
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};
