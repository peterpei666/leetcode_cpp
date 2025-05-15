#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups)
    {
        int n=(int)words.size();
        int dp[n];
        int prev[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=1;
            prev[i]=-1;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(groups[i]!=groups[j]&&dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    prev[i]=j;
                }
            }
        }
        int m=0,p=0;
        for(int i=0;i<n;i++)
        {
            if(dp[i]>m)
            {
                m=dp[i];
                p=i;
            }
        }
        vector<string> ret;
        while(p!=-1)
        {
            ret.push_back(words[p]);
            p=prev[p];
        }
        reverse(ret.begin(),ret.end());
        return ret;
    }
};
