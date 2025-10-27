#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maxAlternatingSum(vector<int>& nums)
    {
        int n = (int)nums.size();
        long long ans = 0;
        for (int i = 0; i < n; i++)
        {
            nums[i] = abs(nums[i]);
        }
        sort(nums.begin(), nums.end(), greater<>());
        for (int i = 0; i < (n + 1) / 2; i++)
        {
            ans += 1LL * nums[i] * nums[i];
        }
        for (int i = (n + 1) / 2; i < n; i++)
        {
            ans -= 1LL * nums[i] * nums[i];
        }
        return ans;
    }
};
