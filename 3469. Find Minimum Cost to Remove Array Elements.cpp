#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int remove(int pre,int idx,vector<vector<int>>& dp,vector<int>& nums)
    {
        if(idx==nums.size())
        {
            return nums[pre];
        }
        if(idx==nums.size()-1)
        {
            return max(nums[pre],nums[idx]);
        }
        if(dp[pre][idx]!=-1)
        {
            return dp[pre][idx];
        }
        int c1=max(nums[pre],nums[idx])+remove(idx+1,idx+2,dp,nums);
        int c2=max(nums[pre],nums[idx+1])+remove(idx,idx+2,dp,nums);
        int c3=max(nums[idx],nums[idx+1])+remove(pre,idx+2,dp,nums);
        dp[pre][idx]=min({c1,c2,c3});
        return dp[pre][idx];
    }
    
    int minCost(vector<int>& nums)
    {
        int n=(int)nums.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return remove(0,1,dp,nums);
    }
};
