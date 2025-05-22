#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long countAlternatingSubarrays(vector<int>& nums)
    {
        int n=(int)nums.size();
        long long cnt=n;
        for(int i=1,prev=0;i<n;i++)
        {
            if(nums[i]!=nums[i-1])
            {
                cnt+=(long long)(i-prev);
            }
            else
            {
                prev=i;
            }
        }
        return cnt;
    }
};
