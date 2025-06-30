#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minPairSum(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=(int)nums.size();
        int l=0,r=n-1;
        while(l<r)
        {
            ans=max(ans,nums[l]+nums[r]);
            l++;
            r--;
        }
        return ans;
    }
};
