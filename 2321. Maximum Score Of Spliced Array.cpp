#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2)
    {
        int n=(int)nums1.size();
        int temp1[100000];
        int temp2[100000];
        int sum1=0,sum2=0;
        int dif1=0,dif2=0,sumA=0,sumB=0;
        for(int i=0;i<n;i++)
        {
            sum1+=nums1[i];
            sum2+=nums2[i];
            temp1[i]=nums2[i]-nums1[i];
            temp2[i]=nums1[i]-nums2[i];
            sumA+=temp1[i];
            sumB+=temp2[i];
            dif1=max(dif1,sumA);
            dif2=max(dif2,sumB);
            sumA=max(0,sumA);
            sumB=max(0,sumB);
        }
        return max(sum1+dif1,sum2+dif2);
    }
};
