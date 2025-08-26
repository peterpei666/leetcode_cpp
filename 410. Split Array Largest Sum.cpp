#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int splitArray(vector<int>& nums, int k)
    {
        int l=nums[0];
        int n=(int)nums.size();
        int pre[n];
        pre[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=pre[i-1]+nums[i];
            l=max(l,nums[i]);
        }
        int r=pre[n-1];
        while(l<r)
        {
            int mid=(l+r)/2;
            int cnt=1,prev=0;
            for(int i=0;i<n;i++)
            {
                if(pre[i]-prev>mid)
                {
                    cnt++;
                    prev=pre[i-1];
                }
            }
            if(cnt>k)
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
