#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int absDifference(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int ans = 0;
        int n = (int)nums.size();
        for (int i = 0; i < k; i++)
        {
            ans += nums[n - i - 1] - nums[i];
        }
        return ans;
    }
};
