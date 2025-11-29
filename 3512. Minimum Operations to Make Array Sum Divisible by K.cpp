#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minOperations(vector<int>& nums, int k)
    {
        int n = (int)nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += nums[i];
        }
        return ans % k;
    }
};
