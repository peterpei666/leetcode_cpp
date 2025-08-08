#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int findMin(vector<int>& nums)
    {
        int l=0,r=(int)nums.size()-1;
        while(l<r)
        {
            int mid=(r+l)/2;
            if(nums[l]==nums[mid]&&nums[mid]==nums[r])
            {
                l++;
                r--;
                continue;
            }
            if(nums[mid]>nums[r])
            {
                l=mid+1;
            }
            else
            {
                r=mid;
            }
        }
        return nums[l];
    }
};
