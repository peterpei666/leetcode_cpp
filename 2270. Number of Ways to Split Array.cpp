#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int waysToSplitArray(vector<int>& nums)
    {
        int cnt=0;
        long long sum2=0;
        for(int i=0;i<nums.size();i++)
        {
            sum2+=nums[i];
        }
        long long sum1=0;
        for(int i=0;i<nums.size()-1;i++)
        {
            sum1+=nums[i];
            sum2-=nums[i];
            if(sum1>=sum2)
            {
                cnt++;
            }
        }
        return cnt;
    }
};
