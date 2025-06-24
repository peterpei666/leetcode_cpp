#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int l=1,r=1e9;
        while(l<r)
        {
            int cur=0;
            int mid=(r-l)/2+l;
            if(mid==0)
            {
                break;
            }
            for(int p:piles)
            {
                cur+=(p+mid-1)/mid;
                if(cur>h)
                {
                    break;
                }
            }
            if(cur<=h)
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};
