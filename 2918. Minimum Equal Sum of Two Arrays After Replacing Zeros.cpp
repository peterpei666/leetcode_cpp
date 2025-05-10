#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2)
    {
        long long sum1=0,count1=0;
        int n=(int)nums1.size();
        for(int i=0;i<n;i++)
        {
            if(nums1[i]==0)
            {
                count1++;
            }
            else
            {
                sum1+=nums1[i];
            }
        }
        long long sum2=0,count2=0;
        n=(int)nums2.size();
        for(int i=0;i<n;i++)
        {
            if(nums2[i]==0)
            {
                count2++;
            }
            else
            {
                sum2+=nums2[i];
            }
        }
        if(count1==0&&count2==0)
        {
            return sum1==sum2?sum1:-1;
        }
        if(count1==0)
        {
            return sum2+count2<=sum1?sum1:-1;
        }
        if(count2==0)
        {
            return sum1+count1<=sum2?sum2:-1;
        }
        return max(sum1+count1,sum2+count2);
    }
};
