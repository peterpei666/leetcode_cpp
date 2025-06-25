#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    long long count(vector<int>& nums1,vector<int>& nums2,long long target)
    {
        long long cnt=0;
        for(int i:nums1)
        {
            if(i==0)
            {
                if(target>=0)
                {
                    cnt+=nums2.size();
                }
                continue;
            }
            int l=0;
            int r=(int)nums2.size();
            while(l<r)
            {
                int mid=(r+l)/2;
                long long temp=(long long)i*nums2[mid];
                if(temp<=target)
                {
                    if(i>0)
                    {
                        l=mid+1;
                    }
                    else
                    {
                        r=mid;
                    }
                }
                else
                {
                    if(i>0)
                    {
                        r=mid;
                    }
                    else
                    {
                        l=mid+1;
                    }
                }
            }
            if(i>0)
            {
                cnt+=l;
            }
            else
            {
                cnt+=nums2.size()-l;
            }
        }
        return cnt;
    }
    
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k)
    {
        long long l=-1e10;
        long long r=1e10;
        while(l<r)
        {
            long long mid=l+(r-l)/2;
            if(count(nums1,nums2,mid)<k)
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
