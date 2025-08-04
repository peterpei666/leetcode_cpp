#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int n=(int)prices.size(),temp;
        int l[n];
        l[0]=0;
        temp=prices[0];
        for(int i=1;i<n;i++)
        {
            temp=min(temp,prices[i]);
            l[i]=max(l[i-1],prices[i]-temp);
        }
        int r[n];
        r[n-1]=0;
        temp=prices[n-1];
        for(int i=n-2;i>=0;i--)
        {
            temp=max(temp,prices[i]);
            r[i]=max(r[i+1],temp-prices[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans=max(ans,l[i]+r[i]);
        }
        return ans;
    }
};
