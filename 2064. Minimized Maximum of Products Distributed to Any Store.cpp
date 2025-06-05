#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimizedMaximum(int n, vector<int>& quantities)
    {
        int l,r,ans=-1;
        l=1;
        r=0;
        for(int i:quantities)
        {
            r=max(i,r);
        }
        while(r>=l)
        {
            int mid=(r-l)/2+l;
            if(mid==0)
            {
                break;
            }
            int temp=0;
            for(int q:quantities)
            {
                temp+=q/mid;
                if(q%mid)
                {
                    temp++;
                }
            }
            if(temp<=n)
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return ans;
    }
};
