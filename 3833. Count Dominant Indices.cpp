#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int dominantIndices(vector<int>& nums)
    {
        int n = (int)nums.size();
        int suf = nums[n - 1];
        int ans = 0;
        for (int i = n - 2; i >= 0; i--)
        {
            if (nums[i] * (n - 1 - i) > suf)
            {
                ans++;
            }
            suf += nums[i];
        }
        return ans;
    }
};
