#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool palindrome(int n)
    {
        int temp=n,sum=0;
        while(n)
        {
            sum*=10;
            sum+=n%10;
            n/=10;
        }
        return sum==temp;
    }
    
    inline long long cost(vector<int>& nums,int t)
    {
        long long ans=0;
        for(int n:nums)
        {
            ans+=abs(n-t);
        }
        return ans;
    }
    
    long long minimumCost(vector<int>& nums)
    {
        int n=(int)nums.size();
        int mid;
        sort(nums.begin(),nums.end());
        if(n&1)
        {
            mid=nums[n/2];
        }
        else
        {
            mid=(nums[n/2]+nums[(n+1)/2])/2;
        }
        long long cost1=1e15;
        if(palindrome(mid))
        {
            cost1=cost(nums,mid);
        }
        bool l=true,r=true;
        int low=mid-1;
        int high=mid+1;
        while(l||r)
        {
            if(l&&palindrome(low))
            {
                l=false;
                cost1=min(cost1,cost(nums,low));
            }
            if(r&&palindrome(high))
            {
                r=false;
                cost1=min(cost1,cost(nums,high));
            }
            low--;
            high++;
        }
        return cost1;
    }
};
