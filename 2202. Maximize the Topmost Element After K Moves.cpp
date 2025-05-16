#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumTop(vector<int>& nums, int k)
    {
        int n=(int)nums.size();
        if(n==1&&k%2)
        {
            return -1;
        }
        if(k==1)
        {
            return nums[1];
        }
        int m=0;
        for(int i=0;i<k-1&&i<n;i++)
        {
            m=max(m,nums[i]);
        }
        if(k<n)
        {
            m=max(m,nums[k]);
        }
        return m;
    }
};
