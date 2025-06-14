#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
    private:
    int dfs(int p,vector<int>& arr,vector<int>& dp,int n,int d)
    {
        if(dp[p])
        {
            return dp[p];
        }
        dp[p]=1;
        for(int i=p-1;i>=max(0,p-d)&&arr[i]<arr[p];i--)
        {
            dp[p]=max(dp[p],1+dfs(i,arr,dp,n,d));
        }
        for(int i=p+1;i<=min(n-1,p+d)&&arr[i]<arr[p];i++)
        {
            dp[p]=max(dp[p],1+dfs(i,arr,dp,n,d));
        }
        return dp[p];
    }
    
public:
    int maxJumps(vector<int>& arr, int d)
    {
        int ret=0;
        int n=(int)arr.size();
        vector<int> dp(n,0);
        for(int i=0;i<n;i++)
        {
            ret=max(ret,dfs(i,arr,dp,n,d));
        }
        return ret;
    }
};
