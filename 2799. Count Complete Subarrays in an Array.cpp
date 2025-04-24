#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    int countCompleteSubarrays(vector<int>& nums)
    {
        short count[2000]={0};
        short dif=0;
        for(int i:nums)
        {
            if(count[i-1]==0)
            {
                dif++;
            }
            count[i-1]++;
        }
        memset(count,0,sizeof(count));
        int res=0;
        short temp=0,right=0;
        for(short left=0;left<nums.size();left++)
        {
            if(left>0)
            {
                count[nums[left-1]-1]--;
                if(count[nums[left-1]-1]==0)
                {
                    temp--;
                }
            }
            while(right<nums.size()&&temp<dif)
            {
                if(count[nums[right]-1]==0)
                {
                    temp++;
                }
                count[nums[right]-1]++;
                right++;
            }
            if(temp==dif)
            {
                res+=nums.size()-right+1;
            }
        }
        return res;
    }
};
