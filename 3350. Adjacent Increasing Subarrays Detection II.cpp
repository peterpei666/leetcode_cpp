#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxIncreasingSubarrays(vector<int>& nums)
    {
        int mp[200000];
        mp[0] = 1;
        int n = (int)nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] > nums[i - 1])
            {
                mp[i] = mp[i - 1] + 1;
            }
            else
            {
                mp[i] = 1;
            }
        }
        int l = 1;
        int r = n / 2;
        int ans = 1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            bool valid = false;
            for (int i = 0; i <= n - 2 * mid; i++)
            {
                if (mp[i + mid - 1] - mp[i] == mid - 1 && mp[i + 2 * mid - 1] - mp[i + mid] == mid - 1)
                {
                    valid = true;
                    break;
                }
            }
            if (valid)
            {
                ans = mid;
                l = mid + 1;
            }
            else
            {
                r = mid - 1;
            }
        }
        return ans;
    }
};
