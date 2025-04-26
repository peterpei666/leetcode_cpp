#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int maxRemovals(string source, string pattern, vector<int>& targetIndices)
    {
        const short MIN=-32768;
        bitset<3000> mp;
        for(int i:targetIndices)
        {
            mp.set(i);
        }
        int len1=(int)source.size();
        int len2=(int)pattern.size();
        vector<short> dp(len2+1,MIN);
        dp[len2]=0;
        for(int i=len1-1;i>=0;i--)
        {
            int d=mp.test(i);
            for(int j=0;j<=len2;j++)
            {
                dp[j]+=d;
                if(j<len2&&source[i]==pattern[j])
                {
                    dp[j]=max(dp[j],dp[j+1]);
                }
            }
        }
        return dp[0];
    }
};
