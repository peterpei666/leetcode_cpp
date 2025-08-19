#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minPatches(vector<int>& nums, int n)
    {
        int sz=(int)nums.size();
        long long miss=1;
        int ans=0;
        int i=0;
        while(miss<n)
        {
            if(i<sz&&miss>=nums[i])
            {
                miss+=nums[i];
                i++;
            }
            else
            {
                miss*=2;
                ans++;
            }
        }
        return ans;
    }
};
