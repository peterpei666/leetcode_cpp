#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int sortPermutation(vector<int>& nums)
    {
        int ans = -1;
        int n = (int)nums.size();
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != i)
            {
                ans &= nums[i];
            }
        }
        return ans == -1 ? 0 : ans;
    }
};
