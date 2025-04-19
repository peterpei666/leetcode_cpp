#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK)
    {
        int sz=(int)nums.size(),minp=-1,maxp=-1,invalidp=-1;
        long long count=0;
        for(int i=0;i<sz;i++)
        {
            if(nums[i]<minK||nums[i]>maxK)
            {
                invalidp=i;
            }
            if(nums[i]==minK)
            {
                minp=i;
            }
            if(nums[i]==maxK)
            {
                maxp=i;
            }
            int temp=min(minp,maxp);
            if(temp>invalidp)
            {
                count+=(long long)(temp-invalidp);
            }
        }
        return count;
    }
};
