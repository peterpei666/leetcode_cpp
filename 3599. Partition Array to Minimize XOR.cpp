#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
private:
    bitset<260> memo[260];
    
    bool valid(vector<int>& nums,int n,int limit,int k)
    {
        for(int i=0;i<=n;i++)
        {
            memo[i].reset();
        }
        for(int i=0;i<n;i++)
        {
            int temp=0;
            for(int j=i;j<n;j++)
            {
                temp^=nums[j];
                if(temp<=limit)
                {
                    memo[i].set(j+1);
                }
            }
        }
        bitset<260> cur,next;
        cur.set(0);
        for(int m=0;m<k;m++)
        {
            next.reset();
            for(int i=0;i<=n;i++)
            {
                if(cur.test(i))
                {
                    next|=memo[i];
                }
            }
            if(!next.any())
            {
                return false;
            }
            cur=next;
        }
        return cur.test(n);
    }
    
public:
    int minXor(vector<int>& nums, int k)
    {
        int n=(int)nums.size();
        int l=0,r=0;
        for(int i:nums)
        {
            r|=i;
        }
        while(l<r)
        {
            int mid=(r-l)/2+l;
            if(valid(nums,n,mid,k))
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
