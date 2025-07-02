#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int triangularSum(vector<int>& nums)
    {
        while(nums.size()>1)
        {
            vector<int> next;
            for(int i=1;i<nums.size();i++)
            {
                next.push_back((nums[i]+nums[i-1])%10);
            }
            nums=next;
        }
        return nums[0];
    }
};
