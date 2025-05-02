#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long pickGifts(vector<int>& gifts, int k)
    {
        int m=0,mp=-1,sz;
        sz=(int)gifts.size();
        while(k)
        {
            m=0;
            mp=-1;
            for(int i=0;i<sz;i++)
            {
                if(gifts[i]>m)
                {
                    m=gifts[i];
                    mp=i;
                }
            }
            gifts[mp]=(int)sqrt(m);
            k--;
        }
        long long sum=0;
        for(int i:gifts)
        {
            sum+=(long long)i;
        }
        return sum;
    }
};
