#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int partitionArray(vector<int>& nums, int k)
    {
        sort(nums.begin(),nums.end());
        int ans=1;
        int cur=nums[0];
        int n=(int)nums.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]-cur>k)
            {
                ans++;
                cur=nums[i];
            }
        }
        return ans;
    }
};
