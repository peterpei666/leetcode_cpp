#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumLength(vector<int>& nums, int k)
    {
        int dp[k][k];
        int ans=0;
        memset(dp,0,sizeof(dp));
        for(int num:nums)
        {
            num%=k;
            for(int i=0;i<k;i++)
            {
                dp[i][num]=dp[num][i]+1;
                ans=max(dp[i][num],ans);
            }
        }
        return ans;
    }
};
