#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool dfs(int i,int j,const string& s,const string& p,vector<vector<int>>& dp)
    {
        if(i<0&&j<0)
        {
            return true;
        }
        if(j<0)
        {
            return false;
        }
        if(i<0)
        {
            for(int k=0;k<=j;k++)
            {
                if(p[k]!='*')
                {
                    return false;
                }
            }
            return true;
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        if(p[j]==s[i]||p[j]=='?')
        {
            return dp[i][j]=dfs(i-1,j-1,s,p,dp);
        }
        else if(p[j]=='*')
        {
            return dp[i][j]=dfs(i,j-1,s,p,dp)||dfs(i-1,j,s,p,dp);
        }
        return dp[i][j]=false;
    }
    
public:
    bool isMatch(const string& s,const string& p)
    {
        int m=(int)s.size();
        int n=(int)p.size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        return dfs(m-1,n-1,s,p,dp);
    }
};
