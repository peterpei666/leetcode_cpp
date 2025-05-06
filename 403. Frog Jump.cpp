#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    bool canCross(vector<int>& stones)
    {
        const int n=(int)stones.size();
        bitset<2004> mp[n];
        mp[0].set(1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int dif=stones[i]-stones[j];
                if(dif<=n&&mp[j].test(dif))
                {
                    if(i==n-1)
                    {
                        return true;
                    }
                    mp[i].set(dif);
                    if(dif-1>=0)
                    {
                        mp[i].set(dif-1);
                    }
                    if(dif+1<=n)
                    {
                        mp[i].set(dif+1);
                    }
                }
            }
        }
        return false;
    }
};
