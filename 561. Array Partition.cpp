#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int arrayPairSum(vector<int>& nums)
    {
        int n = (int)nums.size();
        int ans = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i += 2)
        {
            ans += min(nums[i], nums[i + 1]);
        }
        return ans;
    }
};
