#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    const int mod=1e9+7;
    long long getwords(vector<string>& words,const string& target,int tidx,int widx,int freq[][26],vector<vector<long long>>& dp)
    {
        if(tidx==target.size())
        {
            return 1;
        }
        if(widx==words[0].size()||words[0].size()-widx<target.size()-tidx)
        {
            return 0;
        }
        if(dp[widx][tidx]!=-1)
        {
            return dp[widx][tidx];
        }
        long long way=0;
        way+=getwords(words,target,tidx,widx+1,freq,dp);
        way+=freq[widx][target[tidx]-'a']*getwords(words,target,tidx+1,widx+1,freq,dp);
        dp[widx][tidx]=way%mod;
        return dp[widx][tidx];
    }
    
public:
    int numWays(vector<string>& words,const string& target)
    {
        vector<vector<long long>> dp(words[0].size(),vector<long long>(target.size(),-1));
        int freq[words[0].size()][26];
        memset(freq,0,sizeof(freq));
        for(int i=0;i<words.size();i++)
        {
            for(int j=0;j<words[0].size();j++)
            {
                freq[j][words[i][j]-'a']++;
            }
        }
        return (int)getwords(words,target,0,0,freq,dp);
    }
};
