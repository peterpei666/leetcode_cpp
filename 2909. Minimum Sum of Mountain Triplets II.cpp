#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumSum(vector<int>& nums)
    {
        int n=(int)nums.size();
        int prefix[n];
        int suffix[n];
        prefix[0]=nums[0];
        for(int i=1;i<n;i++)
        {
            prefix[i]=min(prefix[i-1],nums[i]);
        }
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=min(suffix[i+1],nums[i]);
        }
        int ans=INT_MAX;
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]>prefix[i]&&nums[i]>suffix[i])
            {
                ans=min(ans,prefix[i]+nums[i]+suffix[i]);
            }
        }
        return ans==INT_MAX?-1:ans;
    }
};
