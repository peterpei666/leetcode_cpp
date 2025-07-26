#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maxSubarrays(int n, vector<vector<int>>& conflictingPairs)
    {
        vector<int> bmin1(n+1,INT_MAX);
        vector<int> bmin2(n+1,INT_MAX);
        for(auto& pair:conflictingPairs)
        {
            int a=min(pair[0],pair[1]);
            int b=max(pair[0],pair[1]);
            if(bmin1[a]>b)
            {
                bmin2[a]=bmin1[a];
                bmin1[a]=b;
            }
            else if(bmin2[a]>b)
            {
                bmin2[a]=b;
            }
        }
        int b1=n,b2=INT_MAX;
        long long ans=0;
        vector<long long> delcount(n+1,0);
        for(int i=n;i>=1;i--)
        {
            if(bmin1[b1]>bmin1[i])
            {
                b2=min(b2,bmin1[b1]);
                b1=i;
            }
            else
            {
                b2=min(b2,bmin1[i]);
            }
            ans+=min(bmin1[b1],n+1)-i;
            delcount[b1]+=min(min(b2,bmin2[b1]),n+1)-min(bmin1[b1],n+1);
        }
        return ans+*max_element(delcount.begin(),delcount.end());
    }
};
