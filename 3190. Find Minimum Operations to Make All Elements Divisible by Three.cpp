#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumOperations(vector<int>& nums)
    {
        int n = (int)nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans += (nums[i] % 3 != 0);
        }
        return ans;
    }
};
