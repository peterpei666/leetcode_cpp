#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int mod = 1e9 + 7;
    vector<int> nums[51];
    
public:
    Solution()
    {
        for (int i = 0; i <= 5000; i++)
        {
            int t = 0;
            for (int cur = i; cur; cur /= 10)
            {
                t += cur % 10;
            }
            nums[t].push_back(i);
        }
    }
    
    int countArrays(vector<int>& digitSum)
    {
        int n = (int)digitSum.size();
        int prefix[5001] = {0};
        for (int cur : nums[digitSum[0]])
        {
            prefix[cur] = 1;
        }
        for (int k = 1; k <= 5000; k++)
        {
            prefix[k] = (prefix[k] + prefix[k - 1]) % mod;
        }
        for (int i = 1; i < n; i++)
        {
            int dp[5001] = {0};
            for (int cur : nums[digitSum[i]])
            {
                dp[cur] = prefix[cur];
            }
            for (int k = 1; k <= 5000; k++)
            {
                dp[k] = (dp[k] + dp[k - 1]) % mod;
            }
            memcpy(prefix, dp, sizeof(dp));
        }
        return prefix[5000];
    }
};
