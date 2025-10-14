#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    bool check(vector<int>& nums, int idx, int k)
    {
        for (int i = idx + 1; i < idx + k; i++)
        {
            if (nums[i] <= nums[i - 1])
            {
                return false;
            }
        }
        return true;
    }
    
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k)
    {
        int n = (int)nums.size();
        for (int i = 0; i <= n - 2 * k; i++)
        {
            if (check(nums, i, k) && check(nums, i + k, k))
            {
                return true;
            }
        }
        return false;
    }
};
