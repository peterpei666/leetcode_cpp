#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool uniformArray(vector<int>& nums1)
    {
        int n = (int)nums1.size();
        int odd = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            if (nums1[i] & 1)
            {
                odd = min(odd, nums1[i]);
            }
        }
        bool valid_odd = true;
        bool valid_even = true;
        for (int i = 0; i < n; i++)
        {
            if (nums1[i] & 1)
            {
                valid_even &= nums1[i] > odd;
            }
            else
            {
                valid_odd &= nums1[i] > odd;
            }
        }
        return valid_odd || valid_even;
    }
};
