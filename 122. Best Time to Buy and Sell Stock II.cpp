#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProfit(vector<int>& prices)
    {
        int ans=0,cur=prices[0];
        for(int p:prices)
        {
            if(p>cur)
            {
                ans+=p-cur;
            }
            cur=p;
        }
        return ans;
    }
};
