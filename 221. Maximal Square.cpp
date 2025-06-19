#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximalSquare(vector<vector<char>>& matrix)
    {
        int m=(int)matrix.size();
        int n=(int)matrix[0].size();
        int dp[m][n];
        memset(dp,0,sizeof(dp));
        int len=0;
        for(int i=0;i<m;i++)
        {
            dp[i][0]=matrix[i][0]-'0';
            len=max(len,dp[i][0]);
        }
        for(int i=1;i<n;i++)
        {
            dp[0][i]=matrix[0][i]-'0';
            len=max(len,dp[0][i]);
        }
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]=='1')
                {
                    dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
                    len=max(dp[i][j],len);
                }
            }
        }
        return len*len;
    }
};
