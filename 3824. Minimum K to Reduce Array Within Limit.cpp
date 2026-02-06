#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumK(vector<int>& nums)
    {
        int n = (int)nums.size();
        int l = 0, r = 100000;
        while (l < r)
        {
            int mid = (r - l) / 2 + l;
            if (mid == 0)
            {
                break;
            }
            long long cost = 0;
            for (int i = 0; i < n; i++)
            {
                cost += (nums[i] + mid - 1) / mid;
            }
            if (cost > 1LL * mid * mid)
            {
                l = mid + 1;
            }
            else
            {
                r = mid;
            }
        }
        return l == 0 ? 1 : l;
    }
};
