#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int maximumUniqueSubarray(vector<int>& nums)
    {
        int ans=0,sum=0;
        bitset<10000> found;
        for(int i=0,j=0;i<nums.size();i++)
        {
            while(found.test(nums[i]-1))
            {
                sum-=nums[j];
                found.reset(nums[j]-1);
                j++;
            }
            sum+=nums[i];
            found.set(nums[i]-1);
            ans=max(ans,sum);
        }
        return ans;
    }
};
