#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numberOfWays(int n, int x)
    {
        const int mod=1e9+7;
        int dp[2][n+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=1;
        for(int i=1;i<=n;i++)
        {
            long long temp=pow(i,x);
            if(temp>n)
            {
                return dp[(i-1)%2][n];
            }
            memcpy(dp[i%2],dp[(i-1)%2],sizeof(dp[0]));
            for(int j=(int)temp;j<=n;j++)
            {
                dp[i%2][j]=(dp[i%2][j]+dp[(i-1)%2][j-temp])%mod;
            }
        }
        return dp[n%2][n];
    }
};
