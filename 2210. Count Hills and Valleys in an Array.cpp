#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countHillValley(vector<int>& nums)
    {
        int n=(int)nums.size();
        int cnt=0;
        for(int i=1;i<n-1;i++)
        {
            if(nums[i]==nums[i-1])
            {
                continue;
            }
            int l=0;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]<nums[i])
                {
                    l=1;
                    break;
                }
                else if(nums[j]>nums[i])
                {
                    l=-1;
                    break;
                }
            }
            int r=0;
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]<nums[i])
                {
                    r=1;
                    break;
                }
                else if(nums[j]>nums[i])
                {
                    r=-1;
                    break;
                }
            }
            if(l==r)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
