#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int>& nums)
    {
        int n = (int)nums.size();
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] == 1)
            {
                cnt++;
            }
        }
        if (cnt)
        {
            return n - cnt;
        }
        int ans = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            int cur = nums[i];
            int j = i + 1;
            while (j < n && cur != 1)
            {
                cur = gcd(cur, nums[j]);
                j++;
            }
            if (cur == 1)
            {
                ans = min(ans, j - i);
            }
        }
        if (ans == INT_MAX)
        {
            return -1;
        }
        return n + ans - 2;
    }
};
