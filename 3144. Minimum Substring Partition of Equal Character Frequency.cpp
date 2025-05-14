#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool valid(int list[26])
    {
        int m1=0;
        for(int i=0;i<26;i++)
        {
            if(list[i]==0)
            {
                continue;
            }
            if(m1==0)
            {
                m1=list[i];
            }
            else
            {
                if(m1!=list[i])
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    inline int mini(int a,int b)
    {
        return a<b?a:b;
    }
    
    int minimumSubstringsInPartition(string& s)
    {
        int n=(int)s.size();
        int dp[n];
        for(int i=0;i<n;i++)
        {
            dp[i]=i+1;
        }
        for(int r=0;r<n;r++)
        {
            int list[26]={0};
            for(int l=r;l>=0;l--)
            {
                list[s[l]-'a']++;
                if(valid(list))
                {
                    dp[r]=mini(dp[r],l==0?1:dp[l-1]+1);
                }
            }
        }
        return dp[n-1];
    }
};
