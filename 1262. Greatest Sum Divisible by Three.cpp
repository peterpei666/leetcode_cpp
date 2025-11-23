#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSumDivThree(vector<int>& nums)
    {
        int n = (int)nums.size();
        int t[2][2];
        memset(t, 0x3f, sizeof(t));
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += nums[i];
            if (nums[i] % 3)
            {
                if (nums[i] < t[nums[i] % 3 - 1][0])
                {
                    t[nums[i] % 3 - 1][1] = t[nums[i] % 3 - 1][0];
                    t[nums[i] % 3 - 1][0] = nums[i];
                }
                else if (nums[i] < t[nums[i] % 3 - 1][1])
                {
                    t[nums[i] % 3 - 1][1] = nums[i];
                }
            }
        }
        if (ans % 3 == 1)
        {
            ans -= min(t[0][0], t[1][0] + t[1][1]);
        }
        else if (ans % 3 == 2)
        {
            ans -= min(t[1][0], t[0][0] + t[0][1]);
        }
        return ans;
    }
};
