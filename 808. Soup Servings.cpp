#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
private:
    static inline double cal(unordered_map<int,unordered_map<int,double>>& dp,int i,int j)
    {
        return (dp[max(0,i-4)][j]+dp[max(0,i-3)][j-1]+dp[max(0,i-2)][max(0,j-2)]+dp[i-1][max(0,j-3)])/4;
    }
    
public:
    double soupServings(int n)
    {
        int m=ceil(n/25.0);
        unordered_map<int,unordered_map<int,double>> dp;
        dp[0][0]=0.5;
        for(int i=1;i<=m;i++)
        {
            dp[0][i]=1.0;
            dp[i][0]=0.0;
            for(int j=1;j<=i;j++)
            {
                dp[j][i]=cal(dp,j,i);
                dp[i][j]=cal(dp,i,j);
            }
            if(dp[i][i]>1-1e-5)
            {
                return 1.0;
            }
        }
        return dp[m][m];
    }
};
