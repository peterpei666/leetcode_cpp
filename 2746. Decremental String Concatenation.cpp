#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimizeConcatenatedLength(vector<string>& words)
    {
        int n=(int)words.size();
        int dp[2][26][26];
        memset(dp,-1,sizeof(dp));
        int total=(int)words[0].size();
        dp[0][words[0][0]-'a'][words[0][total-1]-'a']=0;
        int ans=0;
        for(int k=1;k<n;k++)
        {
            int len=(int)words[k].size();
            total+=len;
            int cur=k&1;
            memset(dp[cur],-1,sizeof(dp[cur]));
            for(int i=0;i<26;i++)
            {
                for(int j=0;j<26;j++)
                {
                    if(dp[cur^1][i][j]==-1)
                    {
                        continue;
                    }
                    dp[cur][words[k][0]-'a'][j]=max(dp[cur][words[k][0]-'a'][j],dp[cur^1][i][j]+(words[k][len-1]-'a'==i));
                    dp[cur][i][words[k][len-1]-'a']=max(dp[cur][i][words[k][len-1]-'a'],dp[cur^1][i][j]+(words[k][0]-'a'==j));
                    ans=max(ans,max(dp[cur][words[k][0]-'a'][j],dp[cur][i][words[k][len-1]-'a']));
                }
            }
        }
        return total-ans;
    }
};
