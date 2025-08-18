#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    vector<long long> pre;
    int lower,upper;
    int ans;
    
    void merge_sort(int l,int r)
    {
        if(l>=r)
        {
            return;
        }
        int mid=(l+r)/2;
        merge_sort(l,mid);
        merge_sort(mid+1,r);
        int i=mid+1;
        int j=mid+1;
        for(int k=l;k<=mid;k++)
        {
            while(i<=r&&pre[i]-pre[k]<lower)
            {
                i++;
            }
            while(j<=r&&pre[j]-pre[k]<=upper)
            {
                j++;
            }
            ans+=j-i;
        }
        merge(l,mid,r);
    }
    
    void merge(int l,int mid,int r)
    {
        vector<long long> temp(r-l+1);
        memcpy(&temp[0],&pre[0]+l,sizeof(long long)*(r-l+1));
        int i=l,j=mid+1;
        int idx=l;
        while(i<=mid&&j<=r)
        {
            if(temp[i-l]<temp[j-l])
            {
                pre[idx]=temp[i-l];
                i++;
            }
            else
            {
                pre[idx]=temp[j-l];
                j++;
            }
            idx++;
        }
        while(i<=mid)
        {
            pre[idx]=temp[i-l];
            i++;
            idx++;
        }
    }
    
public:
    int countRangeSum(vector<int>& nums, int lower, int upper)
    {
        this->ans=0;
        this->lower=lower;
        this->upper=upper;
        int n=(int)nums.size();
        pre.resize(n+1);
        pre[0]=0;
        for(int i=0;i<n;i++)
        {
            pre[i+1]=pre[i]+nums[i];
        }
        merge_sort(0,n);
        return ans;
    }
};
