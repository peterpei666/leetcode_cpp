#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maxArrayValue(vector<int>& nums)
    {
        long long temp=0,ret=0;
        int n=(int)nums.size();
        for(int i=n-1;i>=0;i--)
        {
            if(temp>=nums[i])
            {
                temp+=nums[i];
            }
            else
            {
                ret=max(ret,temp);
                temp=nums[i];
            }
        }
        ret=max(ret,temp);
        return ret;
    }
};
