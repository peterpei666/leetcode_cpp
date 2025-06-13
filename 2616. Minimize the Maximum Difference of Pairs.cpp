#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool valid(vector<int>& nums,int n,int p,int dif)
    {
        int cnt=0;
        for(int i=0;i<n-1;i++)
        {
            if(nums[i+1]-nums[i]<=dif)
            {
                cnt++;
                i++;
            }
        }
        return cnt>=p;
    }
    
public:
    int minimizeMax(vector<int>& nums, int p)
    {
        sort(nums.begin(),nums.end());
        int n=(int)nums.size();
        int l=0;
        int r=nums[n-1];
        while(l<r)
        {
            int mid=(r-l)/2+l;
            if(valid(nums,n,p,mid))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
};
