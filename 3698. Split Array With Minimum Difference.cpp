#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long splitArray(vector<int>& nums)
    {
        int n = (int)nums.size();
        bitset<100000> left;
        bitset<100000> right;
        left.set(0);
        for (int i = 1; i < n && nums[i] > nums[i - 1]; i++)
        {
            left.set(i);
        }
        right.set(n - 1);
        for (int i = n - 2; i >= 0 && nums[i] > nums[i + 1]; i--)
        {
            right.set(i);
        }
        long long total = 0;
        for (int i = 0; i < n; i++)
        {
            total += nums[i];
        }
        long long sum = 0;
        long long ans = LLONG_MAX;
        for (int i = 0; i < n - 1 && left.test(i); i++)
        {
            sum += nums[i];
            if (right.test(i + 1))
            {
                ans = min(ans, abs(sum - (total - sum)));
            }
        }
        if (ans == LLONG_MAX)
        {
            ans = -1;
        }
        return ans;
    }
};

