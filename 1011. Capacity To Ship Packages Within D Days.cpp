#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int shipWithinDays(vector<int>& weights, int days)
    {
        int n=(int)weights.size();
        int l=0;
        int r=500*50000;
        for(int i:weights)
        {
            l=max(l,i);
        }
        while(l<r)
        {
            int c=0,d=1;
            int mid=(l+r)/2;
            for(int i=0;i<n&&d<=days;i++)
            {
                c+=weights[i];
                if(c>mid)
                {
                    c=weights[i];
                    d++;
                }
            }
            if(d>days)
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        return l;
    }
};
