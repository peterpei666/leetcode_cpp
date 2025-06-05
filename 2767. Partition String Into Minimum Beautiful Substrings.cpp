#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumBeautifulSubstrings(const string& s)
    {
        int n=(int)s.size();
        int dp[n+1];
        fill(&dp[0],&dp[0]+n+1,n+1);
        dp[0]=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                continue;
            }
            for(int j=i,cur=0;j<n;j++)
            {
                cur=cur*2+s[j]-'0';
                if(78125%cur==0)
                {
                    dp[j+1]=min(dp[j+1],dp[i]+1);
                }
            }
        }
        return dp[n]>n?-1:dp[n];
    }
};
