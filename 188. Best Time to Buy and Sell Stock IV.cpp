#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(int k, vector<int>& prices)
    {
        int n=(int)prices.size();
        int buy[k+1][n];
        int profit[k+1][n];
        memset(buy,0,sizeof(buy));
        memset(profit,0,sizeof(profit));
        for(int i=0;i<n;i++)
        {
            for(int t=1;t<=k;t++)
            {
                if(i>0)
                {
                    buy[t][i]=max(buy[t][i-1],profit[t-1][i-1]-prices[i]);
                }
                else
                {
                    buy[t][i]=-prices[i];
                }
                if(i>0)
                {
                    profit[t][i]=max(profit[t][i-1],buy[t][i]+prices[i]);
                }
            }
        }
        return profit[k][n-1];
    }
};
