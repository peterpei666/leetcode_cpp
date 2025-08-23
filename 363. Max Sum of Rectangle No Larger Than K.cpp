#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k)
    {
        int m=(int)matrix.size();
        int n=(int)matrix[0].size();
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i+1][j+1]=dp[i][j+1]+dp[i+1][j]+matrix[i][j]-dp[i][j];
            }
        }
        int ans=INT_MIN;
        for(int x=m;x>=1;x--)
        {
            for(int y=n;y>=1;y--)
            {
                for(int i=x;i>=1;i--)
                {
                    for(int j=y;j>=1;j--)
                    {
                        int temp=dp[x][y]-dp[i-1][y]-dp[x][j-1]+dp[i-1][j-1];
                        if(temp<=k)
                        {
                            ans=max(ans,temp);
                        }
                    }
                }
                if(ans==k)
                {
                    return k;
                }
            }
        }
        return ans;
    }
};
