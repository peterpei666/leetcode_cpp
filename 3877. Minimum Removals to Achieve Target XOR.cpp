#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minRemovals(vector<int>& nums, int target)
    {
        int n = (int)nums.size();
        int dp[2][16384];
        memset(dp[0], 0x80, sizeof(dp[0]));
        dp[0][0] = 0;
        dp[0][nums[0]] = 1;
        for (int i = 1; i < n; i++)
        {
            int t = i & 1;
            int p = t ^ 1;
            memset(dp[t], 0x80, sizeof(dp[t]));
            for (int k = 0; k < 16384; k++)
            {
                if (dp[p][k] >= 0)
                {
                    dp[t][k ^ nums[i]] = max(dp[t][k ^ nums[i]], dp[p][k] + 1);
                    dp[t][k] = max(dp[t][k], dp[p][k]);
                }
            }
        }
        if (dp[(n - 1) & 1][target] < 0)
        {
            return -1;
        }
        return n - dp[(n - 1) & 1][target];
    }
};
