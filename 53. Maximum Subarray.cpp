#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int maxSubArray(vector<int>& nums)
    {
        int n = (int)nums.size();
        int ans = INT_MIN, temp = 0;
        for (int i = 0; i < n; i++)
        {
            temp += nums[i];
            ans = max(ans, temp);
            temp = max(0, temp);
        }
        return ans;
    }
};
