#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findPaths(int m, int n, int maxMove, int x, int y)
    {
        const int mod=1e9+7;
        int cnt=0;
        int dp[m][n];
        int temp[m][n];
        memset(dp,0,sizeof(dp));
        dp[x][y]=1;
        for(int k=1;k<=maxMove;k++)
        {
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(i==0)
                    {
                        cnt=(cnt+dp[i][j])%mod;
                    }
                    if(j==0)
                    {
                        cnt=(cnt+dp[i][j])%mod;
                    }
                    if(i==m-1)
                    {
                        cnt=(cnt+dp[i][j])%mod;
                    }
                    if(j==n-1)
                    {
                        cnt=(cnt+dp[i][j])%mod;
                    }
                    temp[i][j]=0;
                    if(i>0)
                    {
                        temp[i][j]=(temp[i][j]+dp[i-1][j])%mod;
                    }
                    if(j>0)
                    {
                        temp[i][j]=(temp[i][j]+dp[i][j-1])%mod;
                    }
                    if(i<m-1)
                    {
                        temp[i][j]=(temp[i][j]+dp[i+1][j])%mod;
                    }
                    if(j<n-1)
                    {
                        temp[i][j]=(temp[i][j]+dp[i][j+1])%mod;
                    }
                }
            }
            memcpy(dp,temp,sizeof(temp));
        }
        return cnt;
    }
};
