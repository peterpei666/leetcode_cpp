#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long minArraySum(vector<int>& nums, int k)
    {
        long long dp[k];
        memset(dp, 0x7f, sizeof(dp));
        long long sum = 0;
        dp[0] = 0;
        for (int i : nums)
        {
            sum += i;
            dp[sum % k] = min(dp[sum % k], sum);
            sum = dp[sum % k];
        }
        return sum;
    }
};
