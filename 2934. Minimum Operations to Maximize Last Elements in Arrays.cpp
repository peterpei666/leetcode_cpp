#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2)
    {
        int n=(int)nums1.size();
        int a=nums1[n-1],b=nums2[n-1];
        int m1=min(a,b),m2=max(a,b);
        int c1=0,c2=1;
        for(int i=0;i<n-1;i++)
        {
            if(m1<min(nums1[i],nums2[i])||m2<max(nums1[i],nums2[i]))
            {
                return -1;
            }
            if(!(nums1[i]<=a&&nums2[i]<=b))
            {
                c1++;
            }
            if(!(nums1[i]<=b&&nums2[i]<=a))
            {
                c2++;
            }
        }
        return min(c1,c2);
    }
};
