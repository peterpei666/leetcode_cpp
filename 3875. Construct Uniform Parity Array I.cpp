#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool uniformArray(vector<int>& nums1)
    {
        int n = (int)nums1.size();
        int odd = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums1[i] & 1)
            {
                odd++;
            }
        }
        bool valid_odd = true;
        bool valid_even = true;
        for (int i = 0; i < n; i++)
        {
            if (nums1[i] & 1)
            {
                valid_even &= odd > 1;
            }
            else
            {
                valid_odd &= odd > 0;
            }
        }
        return valid_odd || valid_even;
    }
};
