#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int n = (int)nums.size();
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            ans ^= nums[i];
        }
        return ans;
    }
};
