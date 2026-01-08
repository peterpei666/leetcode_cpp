#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2)
    {
        int m = (int)nums1.size();
        int n = (int)nums2.size();
        int dp[2][501];
        int ans = INT_MIN;
        memset(dp, 0x80, sizeof(dp));
        for (int i = m - 1; i >= 0; i--)
        {
            for (int j = n - 1; j >= 0; j--)
            {
                int x = nums1[i] * nums2[j];
                int temp = dp[i & 1][j];
                temp = max(temp, x);
                temp = max(temp, x + (i + 1 < m && j + 1 < n ? dp[(i + 1) & 1][j + 1] : 0));
                temp = max(temp, dp[i & 1][j + 1]);
                dp[i & 1][j] = max(temp, dp[(i + 1) & 1][j]);
                ans = max(ans, dp[i & 1][j]);
            }
        }
        return ans;
    }
};
