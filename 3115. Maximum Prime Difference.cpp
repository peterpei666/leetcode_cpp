#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    inline bool prime(int x)
    {
        if(x==2)
        {
            return true;
        }
        if(x==1||x%2==0)
        {
            return false;
        }
        for(int i=3,limit=sqrt(x);i<=limit;i+=2)
        {
            if(x%i==0)
            {
                return false;
            }
        }
        return true;
    }
    
public:
    int maximumPrimeDifference(vector<int>& nums)
    {
        int l=-1,r=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(prime(nums[i]))
            {
                if(l==-1)
                {
                    l=i;
                }
                r=i;
            }
        }
        return r-l;
    }
};
