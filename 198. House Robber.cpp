#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int rob(vector<int>& nums)
    {
        int n=(int)nums.size();
        if(n==1)
        {
            return nums[0];
        }
        if(n==2)
        {
            return max(nums[0],nums[1]);
        }
        int dp[3];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n;i++)
        {
            dp[i%3]=max(dp[(i-1)%3],dp[(i-2)%3]+nums[i]);
        }
        return dp[(n-1)%3];
    }
};
