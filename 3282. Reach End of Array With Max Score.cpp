#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long findMaximumScore(vector<int>& nums)
    {
        long long ans=0;
        int i;
        int prev=0;
        for(i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[prev])
            {
                ans+=(long long)nums[prev]*(i-prev);
                prev=i;
            }
        }
        ans+=(long long)(nums.size()-1-prev)*nums[prev];
        return ans;
    }
};
