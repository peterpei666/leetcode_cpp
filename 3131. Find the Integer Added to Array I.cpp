#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int addedInteger(vector<int>& nums1, vector<int>& nums2)
    {
        int m1=10000,m2=10000;
        for(int i:nums1)
        {
            m1=min(m1,i);
        }
        for(int i:nums2)
        {
            m2=min(m2,i);
        }
        return m2-m1;
    }
};
