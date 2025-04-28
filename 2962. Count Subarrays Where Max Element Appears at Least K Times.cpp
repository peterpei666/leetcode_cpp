#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long countSubarrays(vector<int>& nums, int k)
    {
        int m=0;
        for(int i:nums)
        {
            m=max(m,i);
        }
        int start=0,count=0;
        long long ans=0;
        for(int end=0;end<nums.size();end++)
        {
            if(nums[end]==m)
            {
                count++;
            }
            while(count==k)
            {
                if(nums[start]==m)
                {
                    count--;
                }
                start++;
            }
            ans+=(long long)start;
        }
        return ans;
    }
};
