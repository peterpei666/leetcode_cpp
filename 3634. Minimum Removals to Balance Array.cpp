#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minRemoval(vector<int>& nums, int k)
    {
        int n = (int)nums.size();
        sort(nums.begin(), nums.end());
        int l = 0, r = n - 1;
        while (r >= 0 && nums[r] > 1LL * nums[l] * k)
        {
            r--;
        }
        int ans = r - l + 1;
        for (; r < n - 1; l++)
        {
            while (r < n && nums[r] <= 1LL * nums[l] * k)
            {
                r++;
            }
            ans = max(ans, r - l);
        }
        return n - ans;
    }
};
