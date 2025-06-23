#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumBeauty(vector<int>& nums, int k)
    {
        sort(nums.begin(),nums.end());
        int ans=0;
        int n=(int)nums.size();
        for(int i=0,j=0;i<n;i++)
        {
            while(j<n&&nums[j]<=nums[i]+2*k)
            {
                j++;
            }
            ans=max(ans,j-i);
            if(j==n)
            {
                break;
            }
        }
        return ans;
    }
};
