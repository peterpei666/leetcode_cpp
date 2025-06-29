#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numSubseq(vector<int>& nums, int target)
    {
        sort(nums.begin(),nums.end());
        const int mod=1e9+7;
        int n=(int)nums.size();
        int list[n];
        list[0]=1;
        for(int i=1;i<n;i++)
        {
            list[i]=list[i-1]*2%mod;
        }
        int l=0,r=n-1;
        int ans=0;
        while(l<=r)
        {
            if(nums[l]+nums[r]<=target)
            {
                ans=(ans+list[r-l])%mod;
                l++;
            }
            else
            {
                r--;
            }
        }
        return ans;
    }
};
