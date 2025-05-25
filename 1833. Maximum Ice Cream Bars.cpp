#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxIceCream(vector<int>& costs, int coins)
    {
        int m=0;
        for(int c:costs)
        {
            m=max(m,c);
        }
        int cnt[m+1];
        memset(cnt,0,sizeof(cnt));
        for(int c:costs)
        {
            cnt[c]++;
        }
        int ans=0;
        for(int i=1;i<=m;i++)
        {
            if(coins/i>=cnt[i])
            {
                coins-=i*cnt[i];
                ans+=cnt[i];
            }
            else
            {
                ans+=coins/i;
                break;
            }
        }
        return ans;
    }
};
