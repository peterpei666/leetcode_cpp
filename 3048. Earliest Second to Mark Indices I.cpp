#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    bool search(int n,vector<int>& nums,vector<int>& changeIndices,int idx)
    {
        if(idx<n)
        {
            return false;
        }
        int cnt=0;
        int last[n];
        bitset<2000> visited;
        for(int i=0;i<idx;i++)
        {
            last[changeIndices[i]-1]=i;
            visited.set(changeIndices[i]-1);
        }
        if(visited.count()<n)
        {
            return false;
        }
        for(int i=0;i<idx;i++)
        {
            if(i==last[changeIndices[i]-1])
            {
                cnt-=nums[changeIndices[i]-1];
                if(cnt<0)
                {
                    return false;
                }
            }
            else
            {
                cnt++;
            }
        }
        return true;
    }
    
    int earliestSecondToMarkIndices(vector<int>& nums,vector<int>& changeIndices)
    {
        int n=(int)nums.size();
        int m=(int)changeIndices.size();
        int l=0,r=m+1;
        while(l<r)
        {
            int mid=l+(r-l)/2;
            if(search(n,nums,changeIndices,mid))
            {
                r=mid;
            }
            else
            {
                l=mid+1;
            }
        }
        return r==m+1?-1:r;
    }
};
