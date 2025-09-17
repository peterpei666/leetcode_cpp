#include <iostream>
#include <algorithm>
#include <bitset>
using namespace std;

class Solution
{
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k)
    {
        sort(nums.begin(), nums.end());
        int n = (int)nums.size();
        bitset<4001> sum;
        sum.set(0);
        vector<bool> ans(n, false);
        for (int i = 0, x = 1; x <= n; x++)
        {
            while (i < n && nums[i] < x)
            {
                sum |= sum << nums[i];
                i++;
            }
            int bigger = n - i;
            for (int j = 0; j <= bigger && x * j <= k; j++)
            {
                if (sum.test(k - x * j))
                {
                    ans[x - 1] = true;
                    break;
                }
            }
        }
        return ans;
    }
};
