#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        int n = (int)nums.size();
        for (int i = 0; i < n && 2 * nums[i] <= target; i++)
        {
            auto it = lower_bound(nums.begin() + i + 1, nums.end(), target - nums[i]);
            if (it != nums.end() && nums[i] + *it == target)
            {
                return {i + 1, (int)(it - nums.begin() + 1)};
            }
        }
        return {-1, -1};
    }
};
