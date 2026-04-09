#include <iostream>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minAbsoluteDifference(vector<int>& nums)
    {
        int n = (int)nums.size();
        int ans = 1000;
        for (int i = 0; i < n; i++)
        {
            if (nums[i] != 1)
            {
                continue;
            }
            for (int j = 0; j < n; j++)
            {
                if (nums[j] == 2)
                {
                    ans = min(ans, abs(i - j));
                }
            }
        }
        return ans == 1000 ? -1 : ans;
    }
};
