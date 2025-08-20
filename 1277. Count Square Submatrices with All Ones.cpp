#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countSquares(vector<vector<int>>& matrix)
    {
        int m=(int)matrix.size();
        int n=(int)matrix[0].size();
        int dp[2][n];
        int ans=0;
        for(int i=0;i<m;i++)
        {
            memset(dp[i%2],0,sizeof(dp[0]));
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j])
                {
                    if(i*j)
                    {
                        dp[i%2][j]=min(min(dp[(i-1)%2][j],dp[i%2][j-1]),dp[(i-1)%2][j-1])+1;
                    }
                    else
                    {
                        dp[i%2][j]=1;
                    }
                    ans+=dp[i%2][j];
                }
            }
        }
        return ans;
    }
};
