#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxScore(vector<int>& nums)
    {
        sort(nums.begin(),nums.end(),greater<int>());
        long long sum=0;
        int ans=0;
        for(int i=0;i<nums.size()&&sum>=0;i++)
        {
            sum+=nums[i];
            if(sum>0)
            {
                ans++;
            }
        }
        return ans;
    }
};
