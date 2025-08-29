#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int numberOfArithmeticSlices(vector<int>& nums)
    {
        int ans = 0;
        int n = (int)nums.size();
        for (int i = 2, len = 0; i < n; i++)
        {
            if (nums[i] - nums[i - 1] == nums[i - 1] - nums[i - 2])
            {
                len++;
            }
            else
            {
                len = 0;
            }
            ans += len;
        }
        return ans;
    }
};
