#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long maxTotalValue(vector<int>& nums, int k)
    {
        int a = INT_MAX;
        int b = INT_MIN;
        int n = (int)nums.size();
        for (int i = 0; i < n; i++)
        {
            a = min(a, nums[i]);
            b = max(b, nums[i]);
        }
        return 1LL * (b - a) * k;
    }
};
