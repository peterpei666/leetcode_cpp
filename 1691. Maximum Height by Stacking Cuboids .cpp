#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxHeight(vector<vector<int>>& cuboids)
    {
        for(auto& c:cuboids)
        {
            sort(c.begin(),c.end());
        }
        sort(cuboids.begin(),cuboids.end());
        int dp[100];
        int n=(int)cuboids.size();
        for(int i=0;i<n;i++)
        {
            dp[i]=cuboids[i][2];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(cuboids[i][0]>=cuboids[j][0]&&cuboids[i][1]>=cuboids[j][1]&&cuboids[i][2]>=cuboids[j][2])
                {
                    dp[i]=max(dp[i],dp[j]+cuboids[i][2]);
                }
            }
        }
        int ret=0;
        for(int i=0;i<n;i++)
        {
            ret=max(ret,dp[i]);
        }
        return ret;
    }
};
