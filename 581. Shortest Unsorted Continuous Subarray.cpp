#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findUnsortedSubarray(vector<int>& nums)
    {
        int n=(int)nums.size();
        int temp1=nums[n-1];
        int temp2=nums[0];
        int l=-1,r=-2;
        for(int i=0;i<n;i++)
        {
            temp1=min(temp1,nums[n-1-i]);
            temp2=max(temp2,nums[i]);
            if(temp1<nums[n-1-i])
            {
                l=n-i-1;
            }
            if(temp2>nums[i])
            {
                r=i;
            }
        }
        return r-l+1;
    }
};
