#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2)
    {
        int j=0,dis=0;
        int len1=(int)nums1.size();
        int len2=(int)nums2.size();
        for(int i=0;i<len1;i++)
        {
            j=max(j,i);
            while(j+1<len2&&nums2[j+1]>=nums1[i])
            {
                j++;
            }
            dis=max(dis,j-i);
            if(j==len2-1)
            {
                break;
            }
        }
        return dis;
    }
};
