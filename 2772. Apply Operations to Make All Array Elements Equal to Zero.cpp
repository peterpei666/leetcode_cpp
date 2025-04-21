#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Solution
{
public:
    bool checkArray(vector<int>& nums, int k)
    {
        int sum=0,i,numsSize=(int)nums.size();
        for(i=0;i<k&&i<numsSize-k+1;i++)
        {
            nums[i]+=sum;
            if(nums[i]<0)
            {
                return false;
            }
            sum-=nums[i];
        }
        for(;i<numsSize-k+1;i++)
        {
            if(i-k>=0)
            {
                sum+=nums[i-k];
            }
            nums[i]+=sum;
            if(nums[i]<0)
            {
                return false;
            }
            sum-=nums[i];
        }
        for(;i<numsSize;i++)
        {
            if(i-k>=0)
            {
                sum+=nums[i-k];
            }
            if(nums[i]+sum!=0)
            {
                return false;
            }
        }
        return true;
    }
};
