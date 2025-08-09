#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maximumProfit(vector<int>& prices, int k)
    {
        long long res[k+1];
        long long bought[k];
        long long sold[k];
        memset(res,0,sizeof(res));
        memset(bought,0x80,sizeof(bought));
        memset(sold,0,sizeof(sold));
        int n=(int)prices.size();
        for(int i=0;i<n;i++)
        {
            for(int j=k;j>=1;j--)
            {
                res[j]=max(res[j],max(bought[j-1]+prices[i],sold[j-1]-prices[i]));
                bought[j-1]=max(bought[j-1],res[j-1]-prices[i]);
                sold[j-1]=max(sold[j-1],res[j-1]+prices[i]);
            }
        }
        long long ans=0;
        for(int i=0;i<=k;i++)
        {
            ans=max(ans,res[i]);
        }
        return ans;
    }
};
