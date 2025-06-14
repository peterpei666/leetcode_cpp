#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long getDescentPeriods(vector<int>& prices)
    {
        int n=(int)prices.size();
        long long ans=1;
        for(int i=1,j=0;i<n;i++)
        {
            if(prices[i]!=prices[i-1]-1)
            {
                j=i;
            }
            ans+=i-j+1;
        }
        return ans;
    }
};
