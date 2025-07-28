#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int countMaxOrSubsets(vector<int>& nums)
    {
        int n=(int)nums.size();
        int max=0,cnt=0;
        for(int num:nums)
        {
            max|=num;
        }
        for(int mask=1;mask<(1<<n);mask++)
        {
            int temp=0;
            for(int i=0;(1<<i)<=mask;i++)
            {
                if(mask&(1<<i))
                {
                    temp|=nums[i];
                }
            }
            if(temp==max)
            {
                cnt++;
            }
            
        }
        return cnt;
    }
};
