#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int lastStoneWeightII(vector<int>& stones)
    {
        bitset<3001> dp;
        int sum=0;
        dp.set(0);
        for(int m:stones)
        {
            dp=(dp<<m)|dp;
            sum+=m;
        }
        int m=sum/2;
        int n=(int)stones.size();
        for(int i=m;i>=0;i--)
        {
            if(dp.test(i))
            {
                return sum-2*i;
            }
        }
        return 0;
    }
};
