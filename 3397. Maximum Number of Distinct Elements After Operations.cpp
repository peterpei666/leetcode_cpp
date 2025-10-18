#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxDistinctElements(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int temp = INT_MIN;
        int n = (int)nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (temp < nums[i] + k)
            {
                temp = max(temp + 1, nums[i] - k);
                ans++;
            }
        }
        return ans;
    }
};
