#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maximumProduct(vector<int>& nums, int m)
    {
        int n=(int)nums.size();
        int surmin[n];
        int surmax[n];
        surmin[n-1]=nums[n-1];
        surmax[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            surmin[i]=min(surmin[i+1],nums[i]);
            surmax[i]=max(surmax[i+1],nums[i]);
        }
        long long ans=(long long)INT_MIN*10;
        for(int i=0;i<n;i++)
        {
            if(i+m-1>=n)
            {
                break;
            }
            ans=max(ans,(long long)nums[i]*surmax[i+m-1]);
            ans=max(ans,(long long)nums[i]*surmin[i+m-1]);
        }
        return ans;
    }
};
