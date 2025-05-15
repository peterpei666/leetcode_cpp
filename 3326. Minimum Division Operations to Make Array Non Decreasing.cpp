#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int operation(int a,int n)
    {
        for(int i=2;i<=a;i++)
        {
            if(n%i==0)
            {
                return i;
            }
        }
        return -1;
    }
    
    int minOperations(vector<int>& nums)
    {
        int ret=0;
        for(int i=(int)nums.size()-1;i>0;i--)
        {
            if(nums[i]<nums[i-1])
            {
                nums[i-1]=operation(nums[i],nums[i-1]);
                if(nums[i-1]==-1)
                {
                    return -1;
                }
                ret++;
            }
        }
        return ret;
    }
};
