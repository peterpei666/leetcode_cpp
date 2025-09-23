#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k)
    {
        int n = (int)nums.size();
        long long temp = 0;
        for (int i = 0; i < k; i++)
        {
            temp += nums[i];
        }
        long long sum[n - k + 1];
        sum[0] = temp;
        for (int i = k; i < n; i++)
        {
            temp = temp + nums[i] - nums[i - k];
            sum[i - k + 1] = temp;
        }
        int left[n - k + 1];
        left[0] = 0;
        for (int i = 1; i < n - k + 1; i++)
        {
            if (sum[i] > sum[left[i - 1]])
            {
                left[i] = i;
            }
            else
            {
                left[i] = left[i - 1];
            }
        }
        int right[n - k + 1];
        right[n - k] = n - k;
        for (int i = n - k - 1; i >= 0; i--)
        {
            if (sum[i] >= sum[right[i + 1]])
            {
                right[i] = i;
            }
            else
            {
                right[i] = right[i + 1];
            }
        }
        vector<int> ans;
        temp = 0;
        for (int i = k; i <= n - 2 * k; i++)
        {
            if (sum[left[i - k]] + sum[i] + sum[right[i + k]] > temp)
            {
                temp = sum[left[i - k]] + sum[i] + sum[right[i + k]];
                ans = {left[i - k], i, right[i + k]};
            }
        }
        return ans;
    }
};
