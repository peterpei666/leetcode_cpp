#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int n = (int)nums.size();
        vector<unordered_map<long long, int>> dp(n);
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                long long dif = (long long)nums[i] - nums[j];
                dp[i][dif] += dp[j][dif] + 1;
                ans += dp[j][dif];
            }
        }
        return ans;
    }
};
