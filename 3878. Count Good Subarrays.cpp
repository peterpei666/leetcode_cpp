#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    long long countGoodSubarrays(vector<int>& nums)
    {
        int n = (int)nums.size();
        int bit[31];
        vector<int> L(n, 0);
        vector<int> R(n, n - 1);
        for (int i = 0; i < 31; i++)
        {
            bit[i] = -1;
        }
        for (int i = 0; i < n; i++)
        {
            for (int b = 0; b < 31; b++)
            {
                if (nums[i] & (1 << b))
                {
                    bit[b] = i;
                }
                else
                {
                    L[i] = max(L[i], bit[b] + 1);
                }
            }
        }
        for (int i = 0; i < 31; i++)
        {
            bit[i] = n;
        }
        for (int i = n - 1; i >= 0; i--)
        {
            for (int b = 0; b < 31; b++)
            {
                if (nums[i] & (1 << b))
                {
                    bit[b] = i;
                }
                else
                {
                    R[i] = min(R[i], bit[b] - 1);
                }
            }
        }
        long long ans = 0;
        unordered_map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            int l = L[i];
            int r = R[i];
            if (mp.count(nums[i]))
            {
                l = max(l, mp[nums[i]] + 1);
            }
            mp[nums[i]] = i;
            ans += 1LL * (i - l + 1) * (r - i + 1);
        }
        return ans;
    }
};
