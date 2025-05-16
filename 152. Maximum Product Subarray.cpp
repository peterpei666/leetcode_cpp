#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxProduct(vector<int>& nums)
    {
        int n=(int)nums.size();
        int m=-100;
        int temp=1;
        for(int i=0;i<n;i++)
        {
            temp*=nums[i];
            m=max(m,temp);
            if(temp==0)
            {
                temp=1;
            }
        }
        temp=1;
        for(int i=n-1;i>=0;i--)
        {
            temp*=nums[i];
            m=max(m,temp);
            if(temp==0)
            {
                temp=1;
            }
        }
        return m;
    }
};
