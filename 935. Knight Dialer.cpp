#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int sz[10]={2,2,2,2,3,0,3,2,2,2};
    int jump[10][3]={4,6,-1,6,8,-1,7,9,-1,4,8,-1,3,9,0,-1,-1,-1,1,7,0,2,6,-1,1,3,-1,2,4,-1};
    const int mod=1e9+7;
    
    int dfs(int remain,int node,int memo[][10])
    {
        if(remain==0)
        {
            return 1;
        }
        if(memo[remain][node])
        {
            return memo[remain][node];
        }
        int ans=0;
        for(int i=0;i<sz[node];i++)
        {
            ans+=dfs(remain-1,jump[node][i],memo);
            ans%=mod;
        }
        memo[remain][node]=ans;
        return ans;
    }
    
    int knightDialer(int n)
    {
        int memo[n][10];
        memset(memo,0,sizeof(memo));
        int ans=0;
        for(int i=0;i<=9;i++)
        {
            ans+=dfs(n-1,i,memo);
            ans%=mod;
        }
        return ans;
    }
};
