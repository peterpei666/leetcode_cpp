#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minIncrementForUnique(vector<int>& nums)
    {
        sort(nums.begin(),nums.end());
        int sum=0,cur=nums[0];
        int n=(int)nums.size();
        for(int i=1;i<n;i++)
        {
            if(nums[i]<cur+1)
            {
                sum+=cur+1-nums[i];
                cur++;
            }
            else
            {
                cur=nums[i];
            }
        }
        return sum;
    }
};
