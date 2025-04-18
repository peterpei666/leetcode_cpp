#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumGap(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int sz=(int)nums.size(),m=0;
        for(int i=0;i<sz-1;i++)
        {
            m=max(m,nums[i+1]-nums[i]);
        }
        return m;
    }
};
