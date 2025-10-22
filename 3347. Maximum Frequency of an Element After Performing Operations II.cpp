#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
private:
    int check(vector<int>& nums, long long n, long long t, int m)
    {
        int l = (int)(lower_bound(nums.begin(), nums.end(), n) - nums.begin());
        int h = (int)(upper_bound(nums.begin(), nums.end(), n) - nums.begin());
        int ll = (int)(lower_bound(nums.begin(), nums.end(), n - t) - nums.begin());
        int hh = (int)(upper_bound(nums.begin(), nums.end(), n + t) - nums.begin());
        int res = (hh - h) + (l - ll);
        return min(m, res) + (h - l);
    }
    
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations)
    {
        sort(nums.begin(), nums.end());
        int ans = 1;
        for (int i = 0; i < nums.size() - 1; i++) {
            ans = max(check(nums, nums[i], k, numOperations), ans);
            ans = max(check(nums, nums[i] - k, k, numOperations), ans);
            ans = max(check(nums, nums[i] + k, k, numOperations), ans);
        }
        return ans;
    }
};
