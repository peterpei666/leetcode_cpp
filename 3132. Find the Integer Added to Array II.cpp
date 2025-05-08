#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2)
    {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int m=10000,n=(int)nums1.size();
        for(int a=0;a<n-1;a++)
        {
            for(int b=a+1;b<n;b++)
            {
                int i,j,temp=0,f=0,valid=1;
                for(i=0,j=0;i<n&&j<n-2&&valid;i++)
                {
                    if(i!=a&&i!=b)
                    {
                        if(f==0)
                        {
                            temp=nums2[j]-nums1[i];
                            f=1;
                            if(temp>m)
                            {
                                break;
                            }
                        }
                        else
                        {
                            if(temp!=nums2[j]-nums1[i])
                            {
                                valid=0;
                            }
                        }
                        j++;
                    }
                }
                if(valid)
                {
                    m=min(m,temp);
                }
            }
        }
        return m;
    }
};
