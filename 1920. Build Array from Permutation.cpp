#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> buildArray(vector<int>& nums)
    {
        const int MOD=10000;
        for(int i=0;i<nums.size();i++)
        {
            nums[i]+=nums[nums[i]%MOD]%MOD*MOD;
        }
        for(int i=0;i<nums.size();i++)
        {
            nums[i]/=MOD;
        }
        return nums;
    }
};
