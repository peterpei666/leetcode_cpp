#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int>& nums)
    {
        int n = (int)nums.size();
        int ans = 1000000;
        for (int i = 0, j = -1, cur = 0; i < n; i++)
        {
            cur += nums[i];
            while (j + 1 < i && cur - nums[j + 1] >= target)
            {
                cur -= nums[j + 1];
                j++;
            }
            if (cur >= target)
            {
                ans = min(ans, i - j);
            }
        }
        return ans == 1000000 ? 0 : ans;
    }
};
