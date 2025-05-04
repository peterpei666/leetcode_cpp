#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minZeroArray(vector<int>& nums,vector<vector<int>>& queries)
    {
        int l=0,r=(int)queries.size();
        if(form(nums,queries,r)==false)
        {
            return -1;
        }
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(form(nums,queries,mid))
            {
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }
        return l;
    }
    
    bool form(vector<int>& nums,vector<vector<int>>& queries,int k)
    {
        int n=(int)nums.size();
        vector<int> dif(n+1,0);
        for(int i=0;i<k;i++)
        {
            dif[queries[i][0]]-=queries[i][2];
            dif[queries[i][1]+1]+=queries[i][2];
        }
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=dif[i];
            if(nums[i]+sum>0)
            {
                return false;
            }
        }
        return true;
    }
};
