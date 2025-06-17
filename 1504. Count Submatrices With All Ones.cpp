#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numSubmat(vector<vector<int>>& mat)
    {
        int m=(int)mat.size();
        int n=(int)mat[0].size();
        vector<vector<int>> dp(m,vector<int>(n));
        for(int i=0;i<m;i++)
        {
            dp[i][0]=mat[i][0];
        }
        for(int i=0;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    dp[i][j]=0;
                }
                else
                {
                    dp[i][j]=dp[i][j-1]+1;
                }
            }
        }
        int ans=0;
        for(int j=0;j<n;j++)
        {
            for(int i=0;i<m;i++)
            {
                int temp=dp[i][j];
                for(int k=i;k>=0;k--)
                {
                    temp=min(temp,dp[k][j]);
                    if(temp==0)
                    {
                        break;
                    }
                    ans+=temp;
                }
            }
        }
        return ans;
    }
};
