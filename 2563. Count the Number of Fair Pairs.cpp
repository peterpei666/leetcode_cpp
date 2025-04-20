#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper)
    {
        sort(nums.begin(),nums.end());
        int sz=(int)nums.size();
        long long count=0;
        for(int i=0;i<sz;i++)
        {
            if(nums[i]*2>upper)
            {
                break;
            }
            count+=(long long)(upper_bound(nums.begin()+i+1,nums.end(),upper-nums[i])-lower_bound(nums.begin()+i+1,nums.end(),lower-nums[i]));
        }
        return count;
    }
};
