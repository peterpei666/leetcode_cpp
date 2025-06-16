#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumDifference(vector<int>& nums)
    {
        int n=(int)nums.size();
        vector<int> suffix(n);
        suffix[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            suffix[i]=max(suffix[i+1],nums[i]);
        }
        int ans=-1;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]<suffix[i+1])
            {
                ans=max(ans,suffix[i+1]-nums[i]);
            }
        }
        return ans;
    }
};
