#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2)
    {
        int n=(int)nums1.size();
        int k=k1+k2;
        int m=0;
        int dif[n];
        for(int i=0;i<n;i++)
        {
            dif[i]=abs(nums1[i]-nums2[i]);
            m=max(dif[i],m);
        }
        int list[m+1];
        memset(list,0,sizeof(list));
        for(int i=0;i<n;i++)
        {
            list[dif[i]]++;
        }
        for(int i=m;i>0&&k;i--)
        {
            int temp=min(k,list[i]);
            k-=temp;
            list[i]-=temp;
            list[i-1]+=temp;
        }
        long long ret=0;
        for(int i=1;i<=m;i++)
        {
            ret+=(long long)list[i]*i*i;
        }
        return ret;
    }
};
