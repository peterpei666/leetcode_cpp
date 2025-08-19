#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long zeroFilledSubarray(vector<int>& nums)
    {
        long long ans=0;
        int temp=0;
        int n=(int)nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i])
            {
                temp=0;
            }
            else
            {
                temp++;
                ans+=temp;
            }
        }
        return ans;
    }
};
