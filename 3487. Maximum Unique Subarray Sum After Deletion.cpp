#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSum(vector<int>& nums)
    {
        sort(nums.begin(),nums.end(),greater<int>());
        if(nums[0]<=0)
        {
            return nums[0];
        }
        int ans=nums[0];
        int n=(int)nums.size();
        for(int i=1;i<n&&nums[i]>0;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                ans+=nums[i];
            }
        }
        return ans;
    }
};
