#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maxSubarraySum(vector<int>& nums, int k)
    {
        int n=(int)nums.size();
        long long prefix[k];
        long long sum=0;
        for(int i=0;i<k&&i<n;i++)
        {
            sum+=nums[i];
            prefix[i]=sum;
        }
        prefix[k-1]=min(0LL,prefix[k-1]);
        long long ans=sum;
        for(int i=k;i<n;i++)
        {
            sum+=nums[i];
            ans=max(ans,sum-prefix[i%k]);
            prefix[i%k]=min(prefix[i%k],sum);
        }
        return ans;
    }
};
