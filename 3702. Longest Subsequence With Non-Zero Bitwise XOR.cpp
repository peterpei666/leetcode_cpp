#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int longestSubsequence(vector<int>& nums)
    {
        int ans = 0;
        int n = (int)nums.size();
        for (int i = 0; i < n; i++)
        {
            ans ^= nums[i];
        }
        if (ans)
        {
            return n;
        }
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 0)
            {
                return n - 1;
            }
        }
        return 0;
    }
};
