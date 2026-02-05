#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> constructTransformedArray(vector<int>& nums)
    {
        int n = (int)nums.size();
        vector<int> ans(n);
        for (int i = 0; i < n; i++)
        {
            ans[i] = nums[((i + nums[i]) % n + n) % n];
        }
        return ans;
    }
};
