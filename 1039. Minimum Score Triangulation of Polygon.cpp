#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minScoreTriangulation(vector<int>& values)
    {
        int dp[50][50]={0};
        int n=(int)values.size();
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                for(int k=i+1;k<j;k++)
                {
                    dp[i][j]=min(dp[i][j]==0?INT_MAX:dp[i][j],dp[i][k]+values[i]*values[j]*values[k]+dp[k][j]);
                }
            }
        }
        return dp[0][n-1];
    }
};
