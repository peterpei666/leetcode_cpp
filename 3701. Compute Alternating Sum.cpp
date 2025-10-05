#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int alternatingSum(vector<int>& nums)
    {
        int ans = 0;
        int n = (int)nums.size();
        for (int i = 0; i < n; i++)
        {
            if (i & 1)
            {
                ans -= nums[i];
            }
            else
            {
                ans += nums[i];
            }
        }
        return ans;
    }
};
