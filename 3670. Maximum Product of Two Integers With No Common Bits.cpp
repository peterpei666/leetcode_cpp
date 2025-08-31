#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maxProduct(vector<int>& nums)
    {
        int temp = nums[0];
        int n = (int)nums.size();
        for (int i = 0; i < n; i++)
        {
            temp = max(temp, nums[i]);
        }
        int wid = 0;
        while(temp)
        {
            wid++;
            temp /= 2;
        }
        int mask = 1 << wid;
        int dp[mask];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++)
        {
            dp[nums[i]] = nums[i];
        }
        for (int i = 0; i < mask; i++)
        {
            if (dp[i])
            {
                continue;
            }
            for (int j = 0; j < wid; j++)
            {
                if (i & (1 << j))
                {
                    dp[i] = max(dp[i], dp[i ^ (1 << j)]);
                }
            }
        }
        long long ans = 0;
        for (int i : nums)
        {
            ans = max(ans, (long long)i * dp[(mask - 1) ^ i]);
        }
        return ans;
    }
};
