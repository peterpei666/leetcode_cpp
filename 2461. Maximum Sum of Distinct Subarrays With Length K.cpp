#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    long long maximumSubarraySum(vector<int>& nums, int k)
    {
        bitset<100000> found;
        long long sum=0,ans=0;
        for(int l=0,r=0;r<nums.size();r++)
        {
            while(found.test(nums[r]-1))
            {
                found.reset(nums[l]-1);
                sum-=nums[l];
                l++;
            }
            sum+=nums[r];
            found.set(nums[r]-1);
            if(r-l+1==k)
            {
                ans=max(sum,ans);
                found.reset(nums[l]-1);
                sum-=nums[l];
                l++;
            }
        }
        return ans;
    }
};
