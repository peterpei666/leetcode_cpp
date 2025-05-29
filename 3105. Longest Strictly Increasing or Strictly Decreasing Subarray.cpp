#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestMonotonicSubarray(vector<int>& nums)
    {
        int l=1,temp=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>nums[i-1])
            {
                temp++;
            }
            else
            {
                l=max(l,temp);
                temp=1;
            }
        }
        l=max(l,temp);
        temp=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]<nums[i-1])
            {
                temp++;
            }
            else
            {
                l=max(l,temp);
                temp=1;
            }
        }
        l=max(l,temp);
        return l;
    }
};
