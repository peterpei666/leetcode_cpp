#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<vector<int>> subsets(vector<int>& nums)
    {
        int n = (int)nums.size();
        vector<vector<int>> ans(1 << n);
        for (int mask = 0; mask < (1 << n); mask++)
        {
            vector<int> temp(__builtin_popcount(mask));
            for (int i = 0, j = 0; i < n; i++)
            {
                if ((1 << i) & mask)
                {
                    temp[j] = nums[i];
                    j++;
                }
            }
            ans[mask] = temp;
        }
        return ans;
    }
};
