#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumDifference(vector<int>& nums, int k)
    {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        int ans = 100000;
        for (int i = 0; i + k - 1 < n; i++)
        {
            ans = min(ans, nums[i + k - 1] - nums[i]);
        }
        return ans;
    }
};
