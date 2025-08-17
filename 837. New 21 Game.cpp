#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    double new21Game(int n, int k, int maxPts)
    {
        double dp[n+1];
        dp[0]=1.0;
        double s=k?1.0:0.0;
        for(int i=1;i<=n;i++)
        {
            dp[i]=s/maxPts;
            if(i<k)
            {
                s+=dp[i];
            }
            if(i-maxPts>=0&&i-maxPts<k)
            {
                s-=dp[i-maxPts];
            }
        }
        double ans=0.0;
        for(int i=k;i<=n;i++)
        {
            ans+=dp[i];
        }
        return ans;
    }
};
